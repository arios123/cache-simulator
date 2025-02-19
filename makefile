simulation: simulation.o memory.o cache.o set.o block.o addressdecoder.o performancecounter.o
	g++ output/Simulation.o output/Memory.o output/Cache.o output/Set.o output/Block.o output/AddressDecoder.o output/PerformanceCounter.o -o simulation

simulation.o: headers/Memory.h headers/Cache.h
	g++ src/Simulation.cc -c -o output/Simulation.o

memory.o: headers/Memory.h
	g++ src/Memory.cc -c -o output/Memory.o

cache.o: headers/Cache.h headers/AddressDecoder.h
	g++ src/Cache.cc -c -o output/Cache.o

set.o: headers/Set.h headers/Memory.h
	g++ src/Set.cc -c -o output/Set.o

block.o: headers/Block.h headers/Memory.h
	g++ src/Block.cc -c -o output/Block.o

addressdecoder.o: headers/AddressDecoder.h
	g++ src/AddressDecoder.cc -c -o output/AddressDecoder.o

performancecounter.o: headers/PerformanceCounter.h
	g++ src/PerformanceCounter.cc -c -o output/PerformanceCounter.o

clean:
	rm -f *.o
	rm -f simulation
	rm -f output/*.o