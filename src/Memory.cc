#include <stdio.h>
#include "../headers/Memory.h"

Memory::Memory(int size){
    this -> mainMemory = new unsigned char[size];
    for(int i = 0; i < size; i++){
        this -> mainMemory[i] = i%255;
    }
    this -> memorySize = size;
}

unsigned char Memory::getByte(unsigned long address){
    return this -> mainMemory[address];
}

void Memory::setByte(unsigned long address, unsigned char byte){
    this -> mainMemory[address] = byte;
}

int Memory::getMemorySize(){
    return this -> memorySize;
}

void Memory::display(){
    printf("MAIN MEMORY:\n");
    for (int i = 0; i < this -> memorySize; i++) {
        printf("%02x ", this -> mainMemory[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    if (this -> memorySize % 16 != 0) {
        printf("\n");
    }
}