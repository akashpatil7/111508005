try: logic1.c
	cc logic1.c `pkg-config --cflags --libs gtk+-3.0 goocanvas-2.0` -w -o try


