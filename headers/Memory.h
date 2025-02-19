#ifndef MEMORY_H
#define MEMORY_H

class Memory{
    private:
        int memorySize;
        unsigned char* mainMemory;
    
    public:
        Memory(int size);
        unsigned char getByte(unsigned long address); // not sure if its unsigned long or char
        void setByte(unsigned long address, unsigned char byte); // not sure if its unsigned long or char
        int getMemorySize();
        void display();
};

#endif