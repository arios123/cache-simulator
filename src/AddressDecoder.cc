#include <stdio.h>
#include "../headers/AddressDecoder.h"

AddressDecoder::AddressDecoder(int tagBits, int setIndexBits, int blockOffsetBits){
    this -> tagBits = tagBits;
    this -> setIndexBits = setIndexBits;
    this -> blockOffsetBits = blockOffsetBits;
}

unsigned long AddressDecoder::getTag(unsigned long address){
    return (address>>((this -> setIndexBits)+this -> blockOffsetBits));
}

unsigned long AddressDecoder::getSetIndex(unsigned long address){
    return ((address<<(this -> tagBits))>>((this ->tagBits)+(this -> blockOffsetBits)));
}

unsigned long AddressDecoder::getBlockOffset(unsigned long address){
    int what = (this->tagBits)+this->setIndexBits;
    return (address<<what)>>what;
}

unsigned long AddressDecoder::getBlockAddress(unsigned long address){
    return (address>>(this->blockOffsetBits))<<(this -> blockOffsetBits);
}

unsigned long AddressDecoder::getWholeAddress(unsigned long tag, unsigned long address){
    unsigned long noTag = getSetIndex(address);
    noTag=noTag<<this-> blockOffsetBits;
    unsigned long nTag = tag<<((this ->setIndexBits)+(this -> blockOffsetBits));
    return nTag | noTag;
}