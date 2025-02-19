#include <stdio.h>
#include "../headers/PerformanceCounter.h"

PerformanceCounter::PerformanceCounter(){
    this -> hits = 0;
    this -> misses = 0;
    this -> accesses = 0;
    this -> writebacks = 0;
}

void PerformanceCounter::display(){
    printf("\nAcceses: %d\n", this -> accesses);
    printf("Hits: %d\n", this -> hits);
    printf("Misses: %d\n", this -> misses);
    printf("Writebacks: %d\n", this -> writebacks);
    printf("Miss Perc: %lf\n", this -> getMissPerc());
    printf("Writeback Perc: %lf\n", this -> getWritebackPerc());
}

void PerformanceCounter::incAccesses(){
    (this -> accesses)++;
}

void PerformanceCounter::incMisses(){
    (this -> misses)++;
}

void PerformanceCounter::incHits(){
    (this -> hits)++;
}

void PerformanceCounter::incWritebacks(){
    (this -> writebacks)++;
}

double PerformanceCounter::getMissPerc(){
    return ((double)this -> misses/(double)this -> accesses)*100.0;
}

double PerformanceCounter::getWritebackPerc(){
    return ((double)this -> writebacks / (double)this -> accesses) * 100.0;
} 