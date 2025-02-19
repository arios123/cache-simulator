#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

class AddressDecoder{
    private:
        int tagBits;
        int setIndexBits;
        int blockOffsetBits;

    public:
        AddressDecoder(int tagBits, int setIndexBits, int blockOffsetBits);
        unsigned long getTag(unsigned long address);
        unsigned long getSetIndex(unsigned long address);
        unsigned long getBlockOffset(unsigned long address);
        unsigned long getBlockAddress(unsigned long address);
        unsigned long getWholeAddress(unsigned long tag, unsigned long address);
};

#endif