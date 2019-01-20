OBJS = main.o pointerhelper.o
pointers:main.o pointerhelper.o
	g++ -o pointers main.o pointerhelper.o
pointerhelper.o:pointerhelper.h
	g++ pointerhelper.cpp  -c
main.o:pointerhelper.o pointerhelper.h
	g++ main.cpp -c
clean:
	rm -f pointers ${OBJS}
