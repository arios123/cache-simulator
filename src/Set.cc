#include <stdio.h>
#include "../headers/Set.h"
#include "../headers/Memory.h"
#include "../headers/PerformanceCounter.h"

Set::Set(int blocksAmount, int blockSize, Memory* mainMemory, AddressDecoder* ad, PerformanceCounter* pc){
    this -> mainMemory = mainMemory;
    this -> ad = ad;
    this -> blockAmounts = blocksAmount;
    this -> pc = pc;
    this -> blocks = new Block*[blocksAmount];

    for(int i = 0; i < blocksAmount; i++){
        this -> blocks[i] = new Block(blockSize,mainMemory);
    }
}

unsigned char Set::read(unsigned long address){
    int temp = isLoaded(address);
    (this -> pc) -> incAccesses();
    if(temp >= 0){
        this -> pc -> incHits();
    }else{
        this -> pc -> incMisses();
        load(address);
        temp = isLoaded(address);
    }

    this -> blocks[temp] -> setTime();
    return this -> blocks[temp] -> read((this -> ad) -> getBlockOffset(address));
}

void Set::write(unsigned long address, unsigned char addressChangeTo){
    int temp = isLoaded(address);
    (this -> pc) -> incAccesses();
    if(temp >= 0){
        this -> pc -> incHits();
    }else{
        this -> pc -> incMisses();
        load(address);
        temp = isLoaded(address);
    }

    this -> blocks[temp] -> setDirty(1);
    this -> blocks[temp] -> setTime();
    this -> blocks[temp] -> write((this -> ad) -> getBlockOffset(address),addressChangeTo);

}

void Set::display(){
    printf("      Blocks\n");
    for(int i = 0; i < (this -> blockAmounts);i++){
        printf("      %d:\n",i);
        this -> blocks[i] -> display();
    }
}

char Set::isLoaded(unsigned long address){
    char isLoaded = -1;
    unsigned long thisTag = (this -> ad) -> getTag(address);
    for(int i = 0; i < (this -> blockAmounts);i++){
        unsigned long thatTag = this -> blocks[i] -> getTag();
        if(thisTag == thatTag && (this -> blocks[i]) -> getValid() == 1){
            isLoaded = i;
        }
    }
    return isLoaded;
}

void Set::load(unsigned long address){
    char empty = findEmpty();
    if(empty < 0){
        eviction(address);
        empty = findEmpty();
    }
    this -> blocks[empty] -> setValid(1);
    this -> blocks[empty] -> setTime();
    this -> blocks[empty] -> setTag((this -> ad) -> getTag(address));
    this -> blocks[empty] -> loadFromMemory(this -> ad -> getBlockAddress(address));
}

void Set::eviction(unsigned long address){
    long oldest = this -> blocks[0] -> getTime();
    int index = 0;
    for(int i = 0; i < this -> blockAmounts; i++){
        if(this -> blocks[i] -> getTime() < oldest){
            oldest = this -> blocks[i] -> getTime();
            index = i;
        }
    }
    this -> blocks[index] -> setValid(0);
    if(this -> blocks[index] -> getDirty() == 1){
        this -> blocks[index] -> saveToMemory(this -> ad -> getWholeAddress(this -> blocks[index] -> getTag(),address));
        this -> pc -> incWritebacks();
    }

}

char Set::findEmpty(){
    char empty = -1;
    for(int i = 0; i < (this -> blockAmounts);i++){
        if(this -> blocks[i] -> getValid() == 0){
            empty = i;
            break;
        }
    }
    return empty;
}