#Makefile

OBJ = Bank.o Customer.o WaitingList.o Cashier.o DiscreteEventSimulation.o Event.o ClientArrival.o CashierRelease.o

all: depend bank

bank: $(OBJ)
	c++ -o bank.out $(OBJ)

depend:
	sed '/^#DEP/q' Makefile > mk.tmp
	c++ -M *.cpp >> mk.tmp
	mv mk.tmp Makefile

clean: clean_object
	rm -rfv *.out

clean_object:
	rm -rfv *.o
