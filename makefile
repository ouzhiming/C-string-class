program: CMyString.o main.o
	g++ -o program main.o
CMyString.o: CMyString.h
main.o: CMyString.o

.PHONY: clean
clean: 
	rm *.o program
