#ifndef BLOCK_H
#define BLOCK_H
#include "Memory.h"
#include "AddressDecoder.h"

class Block{
    private:
        unsigned char* block;
        Memory* mainMemory;
        int blockSize;
        unsigned long tag;
        int isValid;
        int isDirty;
        long timestamp;

    public:
        Block(int blockSize, Memory* mainMemory);
        unsigned char read(unsigned long address); //right types?
        void write(unsigned long address, unsigned char addressChangeTo); //right types?
        void loadFromMemory(unsigned long address);
        void saveToMemory(unsigned long address);    
        void display();
        int getValid();
        unsigned long getTag();
        void setValid(char valid);
        void setTime();
        void setTag(unsigned long tag);
        long getTime();
        void setDirty(int dirty);
        int getDirty();

};

#endif