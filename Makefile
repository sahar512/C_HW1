.PHONY: all clean loops recursives recursived loopd

CC=gcc
AR=ar rcs
CFLAGS=-Wall

all: mains maindloop maindrec loops recursives recursived loopd

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

mains: main.o libclassrec.a
	$(CC) $(CFLAGS) main.o libclassrec.a -lm -o mains

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) main.o ./libclassloops.so -lm -o maindloop

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) main.o ./libclassrec.so -lm -o maindrec

main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -fPIC -c basicClassification.c

libclassloops.a: advancedClassificationLoop.o basicClassification.o
	$(AR) libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	$(AR) libclassrec.a advancedClassificationRecursion.o basicClassification.o

libclassloops.so: advancedClassificationLoop.o basicClassification.o
	$(CC) $(CFLAGS) -shared advancedClassificationLoop.o basicClassification.o -o libclassloops.so

libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	$(CC) $(CFLAGS) -shared advancedClassificationRecursion.o basicClassification.o -o libclassrec.so              

clean:
	rm -f *.o *.a *so *.gch mains maindloop maindrec