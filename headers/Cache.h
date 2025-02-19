#ifndef CACHE_H
#define CACHE_H
#include "Set.h"
#include "AddressDecoder.h"
#include "Memory.h"
#include "PerformanceCounter.h"

class Cache{
    private:
        Memory* mainMemory;
        int cacheSize;
        int blockSize;
        int setAssociativity;
        int numSets;
        Set** sets;
        AddressDecoder* ad;
        PerformanceCounter* pc;

    public:
        Cache(Memory* mainMemory, int cacheSize, int blockSize, int setAssociativity);
        unsigned char read(unsigned long address);
        void write(unsigned long address, unsigned char addressChangeTo);
        void display();
};

#endif