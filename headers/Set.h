#ifndef SET_H
#define SET_H
#include "Block.h"
#include "AddressDecoder.h"
#include "PerformanceCounter.h"

class Set{
    private:
        Memory* mainMemory;
        AddressDecoder* ad;
        Block** blocks;
        int blockAmounts;
        char isLoaded(unsigned long address);
        PerformanceCounter* pc;
        void load(unsigned long address);
        char findEmpty();
        void eviction(unsigned long address);

    public:
        Set(int blocksAmount, int blockSize, Memory* mainMemory, AddressDecoder* ad, PerformanceCounter* pc);
        unsigned char read(unsigned long address);
        void write(unsigned long address, unsigned char addressChangeTo);
        void display();
};

#endif