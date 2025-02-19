#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H

class PerformanceCounter{
    private:
        int accesses;
        int misses;
        int hits;
        int writebacks;
        double missPerc;
        double writebackPerc;

    public:
        PerformanceCounter();
        void display();
        void incAccesses();
        void incMisses();
        void incHits();
        void incWritebacks();
        double getMissPerc();
        double getWritebackPerc();

};

#endif