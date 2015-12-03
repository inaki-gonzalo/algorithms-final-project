OBJS = UIMS.o Conversion.o SLItemList.o SItem.o TestDrivers.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++0x $(DEBUG)
LFLAGS = -Wall -std=c++0x $(DEBUG)

HashTable : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o HashTable
    
TestDrivers.o : TestDrivers.cpp UIMS.h
	$(CC) $(CFLAGS) TestDrivers.cpp

UIMS.o : UIMS.h UIMS.cpp SItem.h SLItemList.h Conversion.h 
	$(CC) $(CFLAGS) UIMS.cpp

Conversion.o : Conversion.h
	$(CC) $(CFLAGS) Conversion.cpp

SLItemList.o : SLItemList.h SLItemList.cpp SItem.h 
	$(CC) $(CFLAGS) SLItemList.cpp

SItem.o : SItem.h SItem.cpp 
	$(CC) $(CFLAGS) SItem.cpp

