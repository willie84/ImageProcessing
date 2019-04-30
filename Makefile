CC=g++
CCFLAGS=-std=c++11
Imageops: Main.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Imageops main.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Testexec ImageTests.cpp Image.cpp


.cpp.o:
	$(CC) $(CCFLAGS) -c $<


main:
	./Imageops -i lenna_standard.pgm lennainvert.pgm

Testexec: ImageTests.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Testexec ImageTests.cpp Image.cpp




clean:
	rm -f Imageops Testexec *.o
