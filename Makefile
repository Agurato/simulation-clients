#Makefile

OBJ = simulation.o Bank.o Client.o WaitingList.o Cashier.o DES.o Event.o ClientArrival.o CashierRelease.o

all: depend simulation

simulation: $(OBJ)
	c++ -o simulation.out $(OBJ)

depend:
	sed '/^#DEP/q' Makefile > mk.tmp
	c++ -M *.cpp >> mk.tmp
	mv mk.tmp Makefile

clean: clean_object
	rm -rfv mk.tmp
	rm -rfv *.out

clean_object:
	rm -rfv *.o
	
#DEPENDENCIES: don't remove that line
