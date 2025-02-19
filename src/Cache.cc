#include <stdio.h>
#include "../headers/Cache.h"
#include "../headers/AddressDecoder.h"
#include <math.h>
#include "../headers/PerformanceCounter.h"

Cache::Cache(Memory* mainMemory, int cacheSize, int blockSize, int setAssociativity){
    this -> mainMemory = mainMemory;
    this -> cacheSize = cacheSize;
    this -> blockSize = blockSize;
    this -> setAssociativity = setAssociativity;
    int totalBits = (sizeof(unsigned long)*8);
    int blockOffset = log2(blockSize);
    int setIndex = log2((cacheSize/blockSize)/setAssociativity);
    int tag = totalBits-blockOffset-setIndex;
    this -> ad = new AddressDecoder(tag,setIndex,blockOffset);
    this -> numSets = (cacheSize/blockSize)/setAssociativity;
    this -> sets = new Set*[this -> numSets];
    this -> pc = new PerformanceCounter();

    for(int i = 0; i<(cacheSize/blockSize)/setAssociativity; i++){
        this -> sets[i] = new Set(setAssociativity,blockSize,(this -> mainMemory),(this -> ad),this -> pc);
    }
}

unsigned char Cache::read(unsigned long address){
    return (this -> sets[(this -> ad) -> getSetIndex(address)]) -> read(address);
}

void Cache::write(unsigned long address, unsigned char addressChangeTo){
    (this -> sets[(this -> ad) -> getSetIndex(address)]) -> write(address, addressChangeTo);
}

void Cache::display(){
    printf("CACHE:\n");
    for(int i = 0; i<(this -> numSets); i++){
        printf("   Set %d\n",i);
        this -> sets[i] -> display();
    }
    (this -> pc) -> display();
}