OBJ = main.o BrigManager.o Brig.o Cell.o Pirate.o UImanager.o random.o CArray.o Queue.o Borc.o Dorc.o Porc.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

Borc.o:	Borc.cc Borc.h 
	g++ -c Borc.cc

Dorc.o:	Dorc.cc Dorc.h 
	g++ -c Dorc.cc

Porc.o:	Porc.cc Porc.h 
	g++ -c Porc.cc

BrigManager.o:	BrigManager.cc BrigManager.h 
	g++ -c BrigManager.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

Cell.o:	Cell.cc Cell.h defs.h
	g++ -c Cell.cc

Brig.o:	Brig.cc Brig.h defs.h
	g++ -c Brig.cc

Pirate.o:	Pirate.cc Pirate.h
	g++ -c Pirate.cc

Queue.o:	Queue.cc Queue.h
	g++ -c Queue.cc

CArray.o:	CArray.cc CArray.h
	g++ -c CArray.cc

random.o:	random.cc
	g++ -c random.cc

clean:
	rm -f *.o a4

