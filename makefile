OBJS = *.o
pointers:main.o pointerhelper.o
	g++ -o pointers main.o pointerhelper.o
	rm -f ${OBJS}
pointerhelper.o:helper.h
	g++ pointerhelper.cpp  -c
main.o:pointerhelper.o helper.h
	g++ main.cpp -c
notetest:cpp-notes.o 
	g++ -o notetest cpp-notes.o -lpthread
	rm -f ${OBJS}
cpp-notes.o:helper.h
	g++ cpp-notes.cpp -c
clean1:
	rm -f pointers ${OBJS}
clean2:
	rm -f notetest ${OBJS}
