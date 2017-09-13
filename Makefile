#Makefile

OBJ = simulation.o Bank.o Client.o WaitingList.o Cashier.o DiscreteEventSimulation.o Event.o ClientArrival.o CashierRelease.o

all: depend simulation

simulation: $(OBJ)
	c++ -o simulation.out $(OBJ)

depend:
	sed '/^#DEP/q' Makefile > mk.tmp
	c++ -M *.cpp >> mk.tmp
	mv mk.tmp Makefile

clean: clean_object
	rm -rfv *.out

clean_object:
	rm -rfv *.o
	
#DEPENDENCIES: don't remove that line
Bank.o: Bank.cpp /usr/include/stdc-predef.h
Cashier.o: Cashier.cpp /usr/include/stdc-predef.h
CashierRelease.o: CashierRelease.cpp /usr/include/stdc-predef.h
Client.o: Client.cpp /usr/include/stdc-predef.h
ClientArrival.o: ClientArrival.cpp /usr/include/stdc-predef.h
DiscreteEventSimulation.o: DiscreteEventSimulation.cpp \
 /usr/include/stdc-predef.h
Event.o: Event.cpp /usr/include/stdc-predef.h
WaitingList.o: WaitingList.cpp /usr/include/stdc-predef.h
simulation.o: simulation.cpp /usr/include/stdc-predef.h
