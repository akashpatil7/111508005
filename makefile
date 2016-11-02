project: logic.c
	cc logic.c `pkg-config --cflags --libs gtk+-3.0 goocanvas-2.0` -w -o project
clean : 
	rm *.o

