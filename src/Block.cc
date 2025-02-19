#include "../headers/Block.h"
#include "../headers/Memory.h"
#include <stdio.h>
#include <chrono>

Block::Block(int blockSize, Memory* mainMemory){
    this -> mainMemory = mainMemory;
    this -> block = new unsigned char[blockSize];
    this -> blockSize = blockSize;
    this -> isValid = 0;
    this -> isDirty = 0;
    this -> timestamp = 0;
    this -> tag = 0;


    for(int i = 0; i < blockSize; i++){
        this -> block[i] = 0;
    }
}

unsigned long Block::getTag(){
    return this -> tag;
}

int Block::getValid(){
    return this -> isValid;
}

long Block::getTime(){
    return this -> timestamp;
}

int Block::getDirty(){
    return this -> isDirty;
}

unsigned char Block::read(unsigned long address){
    return this -> block[address];
}

void Block::write(unsigned long address, unsigned char addressChangeTo){
    this -> block[address] = addressChangeTo;
}

void Block::setDirty(int dirty){
    this -> isDirty = dirty;
}

void Block::loadFromMemory(unsigned long address){
    for(int i = 0; i < this -> blockSize; i++){
        this -> block[i] = this -> mainMemory -> getByte(address + i);
    }
}

void Block::saveToMemory(unsigned long address){
    for(int i = 0; i < this -> blockSize; i++){
        this -> mainMemory -> setByte(address+i,this -> block[i]);
    }
    this -> isDirty = 0;
}

void Block::display(){
    printf("         valid: %d   tag: %ld   dirty: %d   timestamp: %ld\n",this->isValid,this->tag,this->isDirty,this->timestamp);
    printf("         ");
    for (int i = 0; i < this -> blockSize; i++) {
        printf("%02x ", this -> block[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    if (this -> blockSize % 16 != 0) {
        printf("\n");
    }
}

void Block::setValid(char valid){
    this -> isValid = valid;
}

void Block::setTime(){
    std::chrono::high_resolution_clock m_clock;
    this -> timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
}

void Block::setTag(unsigned long tag){
    this -> tag = tag;
}