compile: readRecords.c insertionSort.c main.c bank.h
	gcc -c readRecords.c
	gcc -c insertionSort.c
	gcc -o sb readRecords.o insertionSort.o main.c

run: sb 10 100 1000 10000 100000
	./sb 10	
	
test: compile dist1.txt dist2.txt dist3.txt dist4.txt
	./sb dist1.txt
	./sb dist2.txt
	./sb dist3.txt
	./sb dist4.txt
