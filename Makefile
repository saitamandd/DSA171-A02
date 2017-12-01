all: dsa171a2

DEFS = -DAVL_USE_HEIGHT -DUSE_CUSTOME_COMPARE_OPS -DUSE_HASH_ID

dsa171a2: dbLib.o requestLib.o main.o processData.o
	g++ main.o dbLib.o requestLib.o processData.o -std=c++11 -o dsa171a2 $(DEFS)
main.o: main.cpp dsaLib.h
	g++ -c main.cpp -std=c++11 $(DEFS)
requestLib.o: requestLib.cpp dsaLib.h
	g++ -c requestLib.cpp -std=c++11 $(DEFS)
dbLib.o: dbLib.cpp dsaLib.h requestLib.h
	g++ -c dbLib.cpp -std=c++11 $(DEFS)
processData.o: processData.cpp dsaLib.h requestLib.h dbLib.h
	g++ -c processData.cpp -std=c++11 $(DEFS)

clean:
	rm *.o dsa171a2
