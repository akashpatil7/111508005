/*************************************************************************
 Copyright (C) 2016 Adheesh Phadke adheesh1996@gmail.com

 This program is a free software, you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2.1 of the License, or
 (at your option) any later version.
  
 This program is redistributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 Lesser General Public Licence for more details.
 ************************************************************************/ 

#include <gtk/gtk.h>
#include <stdio.h>
#include <cairo.h>
#include <goocanvas.h>
#include <string.h>
#include <stdlib.h>

//---Widgets declaration----
GtkWidget *window, *window1, *window2;
GtkWidget *box;
GtkWidget *grid, *grid1;
GtkWidget *switcherbtn, *toggle1, *toggle2, *bulb, *And, *Or, *Not, *Nand, *Nor, *Xor, *Xnor, *wirebtn1, *wirebtn2;
GtkWidget *vpaned;
GtkWidget *frame;
GtkWidget *combo;
GtkWidget *label;
GtkWidget *label1, *label2, *combolabel, *label3 , *l1, *l2;
GtkWidget *switcher1;
GtkWidget *switcher2;
GtkWidget *vseperator;
GtkWidget *file_menu, *help_menu, *menu_bar, *root_menu, *menu_item, *options_menu;
GtkWidget *fixed;
GtkWidget *toggleinput, *toggleoutput;
GtkWidget *canvas;
GtkWidget *okaybtn;
GooCanvasItem *root;
GtkWidget *two, *three, *four;
int sx, sy, offsetx, offsety, px,py, maxx, maxy,gx,gy,ax,ay;
 
//unique identification of switches
char *switchnames[10] = {"switch1","switch2","switch3","switch4","switch5","switch6","switch7","switch8","switch9","switch10"};
char *togglenames[10] = {"toggle1","toggle2","toggle3","toggle4","toggle5","toggle6","toggle7","toggle8","toggle9","toggle10"};
  
int n = 0;
int m = 0;
int start = 0; 
int mode;

static void startoption(GtkWidget *widget, GdkEventButton *event, gpointer data){
		start = 1;		
}

static void stopoption(GtkWidget *widget,GdkEventButton *event, gpointer data){
		start = 0;
}

int s;

//called when user clicks on any point or widget on the grid
//-----FOR TWO INPUT GATES-----
static gboolean button_press_event_1( GtkWidget *w, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gx=(int)event->x_root; //x-coordinate of the cursor with respect to screen
			gy=(int)event->y_root; //y-coordinate of the cursor with respect to screen
			if((event->x == 0 && event->y == 20) || (event->x == 1 && event->y == 20) || (event->x == 1 && event->y == 19) || (event->x == 0 && event->y == 19) || (event->x == 1 && event->y == 21) || (event->x == 0 && event->y == 21)){
				printf("Click the switch/toggle to be connected to port1\n");
				s = 1;
			}
			if((event->x == 0 && event->y == 60) || (event->x == 1 && event->y == 60) || (event->x == 1 && event->y == 59) || (event->x == 0 && event->y == 59) || (event->x == 1 && event->y == 61) || (event->x == 0 && event->y == 61)){
				printf("Click the switch/toggle to be connected to port2\n");
				s = 2;
			}
			if((event->x == 85 && event->y == 40) || (event->x == 85 && event->y == 39) || (event->x == 85 && event->y == 41) || (event->x == 84 && event->y == 39) || (event->x == 84 && event->y == 40) || (event->x == 84 && event->y == 41)){
				printf("Click the switch/toggle to be connected to output\n");
				s = 5;
			}
			//printf("%d %d\n",gx,gy);
		}
	}
	return TRUE;
}

//-----FOR THREE INPUT GATES-----
static gboolean button_press_event_2( GtkWidget *w, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gx=(int)event->x_root; //x-coordinate of the cursor with respect to screen
			gy=(int)event->y_root; //y-coordinate of the cursor with respect to screen
			if((event->x == 0 && event->y == 10) || (event->x == 1 && event->y == 10) || (event->x == 1 && event->y == 9) || (event->x == 0 && event->y == 9) || (event->x == 1 && event->y == 11) || (event->x == 0 && event->y == 11)){
				printf("Click the switch/toggle to be connected to port1\n");
				s = 1;
			}
			if((event->x == 0 && event->y == 40) || (event->x == 1 && event->y == 40) || (event->x == 1 && event->y == 39) || (event->x == 0 && event->y == 39) || (event->x == 1 && event->y == 41) || (event->x == 0 && event->y == 41)){
				printf("Click the switch/toggle to be connected to port2\n");
				s = 2;
			}
			if((event->x == 0 && event->y == 70) || (event->x == 1 && event->y == 70) || (event->x == 1 && event->y == 69) || (event->x == 0 && event->y == 69) || (event->x == 1 && event->y == 71) || (event->x == 0 && event->y == 71)){
				printf("Click the switch/toggle to be connected to port3\n");
				s = 3;
			}
			if((event->x == 85 && event->y == 40) || (event->x == 85 && event->y == 39) || (event->x == 85 && event->y == 41) || (event->x == 84 && event->y == 39) || (event->x == 84 && event->y == 40) || (event->x == 84 && event->y == 41)){
				printf("Click the switch/toggle to be connected to output\n");
				s = 5;
			}
			printf("%d %d\n",gx,gy);
		}
	}
	return TRUE;
}

//-----FOR FOUR INPUT GATES------ 
static gboolean button_press_event_3( GtkWidget *w, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gx=(int)event->x_root; //x-coordinate of the cursor with respect to screen
			gy=(int)event->y_root; //y-coordinate of the cursor with respect to screen
			if((event->x == 0 && event->y == 5) || (event->x == 1 && event->y == 5) || (event->x == 1 && event->y == 4) || (event->x == 0 && event->y == 4) || (event->x == 1 && event->y == 6) || (event->x == 0 && event->y == 6)){
				printf("Click the switch/toggle to be connected to port1\n");
				s = 1;
			}
			if((event->x == 0 && event->y == 35) || (event->x == 1 && event->y == 35) || (event->x == 1 && event->y == 34) || (event->x == 0 && event->y == 34) || (event->x == 1 && event->y == 36) || (event->x == 0 && event->y == 36)){
				printf("Click the switch/toggle to be connected to port2\n");
				s = 2;
			}
			if((event->x == 0 && event->y == 65) || (event->x == 1 && event->y == 65) || (event->x == 1 && event->y == 64) || (event->x == 0 && event->y == 64) || (event->x == 1 && event->y == 66) || (event->x == 0 && event->y == 66)){
				printf("Click the switch/toggle to be connected to port3\n");
				s = 3;
			}
			if((event->x == 0 && event->y == 95) || (event->x == 1 && event->y == 95) || (event->x == 1 && event->y == 94) || (event->x == 0 && event->y == 94) || (event->x == 1 && event->y == 96) || (event->x == 0 && event->y == 96)){
				printf("Click the switch/toggle to be connected to port4\n");
				s = 4;
			}
			if((event->x == 85 && event->y == 50) || (event->x == 85 && event->y == 49) || (event->x == 85 && event->y == 51) || (event->x == 84 && event->y == 49) || (event->x == 84 && event->y == 50) || (event->x == 84 && event->y == 51)){
				printf("Click the switch/toggle to be connected to output\n");
				s = 5;
			}
			printf("%d %d\n",gx,gy);
		}
	}
	return TRUE;
}


//called when user clicks on the input wire in the grid
static gboolean inputwire(GtkWidget *widget, GdkEventButton *event, cairo_t *cr){
	if(start == 0){
		if(event->button == 1)
				gtk_fixed_move(GTK_FIXED(fixed),canvas, gx-596, gy-173);
	}
	else
		return TRUE;
	return TRUE;
}

//called when user clicks on the an output wire in the grid
static gboolean outputwire(GtkWidget *widget, GdkEventButton *event, cairo_t *cr){
	if(start == 0){
		if(event->button == 1)
				gtk_fixed_move(GTK_FIXED(fixed),canvas, gx-506, gy-173);
	}
	else
		return TRUE;
	return TRUE;
}

gboolean value1, value2, value3, value4, value5;
int input1, input2, input3, input4, input5;

//called when user clicks on an input switch in the grid
static gboolean button_press_event_input(GtkWidget *widget, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gtk_fixed_move(GTK_FIXED(fixed),widget, gx-596, gy-176);
			printf("%s\n",gtk_widget_get_name(widget));
			switch(s){
					case 1: printf("%s connected to port 1\n",gtk_widget_get_name(widget));					
							s = 0;			
							break;
				
					case 2: printf("%s connected to port 2\n",gtk_widget_get_name(widget));							
							s = 0;
							break;
			    
					case 3: printf("%s connected to port 3\n",gtk_widget_get_name(widget));					
							s = 0;
							break;
							
					case 4: printf("%s connected to port 4\n",gtk_widget_get_name(widget));
							s = 0;
							break;
							
					case 5: printf("%s connected to output\n",gtk_widget_get_name(widget));
							s = 0;
							break;
			}
					
			if(gtk_switch_get_state(GTK_SWITCH(widget)) == TRUE){
					gtk_switch_set_state(GTK_SWITCH(widget), FALSE);
			}
			else
	    		if(gtk_switch_get_state(GTK_SWITCH(widget)) == FALSE){
						gtk_switch_set_state(GTK_SWITCH(widget), TRUE);	
				}
		}
	}
	
	if(start == 1){
		if (event->type == GDK_BUTTON_PRESS){
			switch(s){
					case 1: printf("%s connected to port 1\n",gtk_widget_get_name(widget));
							value1 = gtk_switch_get_active(GTK_SWITCH(widget));
							if(value1 == TRUE)
									input1 = 1;
							else
								if(value1 == FALSE)	
										input1 = 0;
							s = 0;				
							break;
				
					case 2: printf("%s connected to port 2\n",gtk_widget_get_name(widget));
							value2 = gtk_switch_get_active(GTK_SWITCH(widget));
							if(value2 == TRUE)
									input2 = 1;
							else
								if(value2 == FALSE)	
										input2 = 0;
							s = 0;
							break;
			    
					case 3: printf("%s connected to port 3\n",gtk_widget_get_name(widget));
							value3 = gtk_switch_get_active(GTK_SWITCH(widget));
							if(value3 == TRUE)
									input3 = 1;
							else
								if(value3 == FALSE)	
										input1 = 0;
							s = 0;
							break;
							
					case 4: printf("%s connected to port 4\n",gtk_widget_get_name(widget));
							value4 = gtk_switch_get_active(GTK_SWITCH(widget));
							if(value4 == TRUE)
									input4 = 1;
							else
								if(value4 == FALSE)	
										input4 = 0;
							s = 0;
							break;
							
					case 5: printf("%s connected to output\n",gtk_widget_get_name(widget));
							value5 = gtk_switch_get_active(GTK_SWITCH(widget));
							if(value5 == TRUE)
									input5 = 1;
							else
								if(value5 == FALSE)	
										input5 = 0;
							s = 0;
							break;
				}
			}
			if(gtk_switch_get_state(GTK_SWITCH(widget)) == TRUE)
					gtk_switch_set_state(GTK_SWITCH(widget), FALSE);
			else
	    		if(gtk_switch_get_state(GTK_SWITCH(widget)) == FALSE)
						gtk_switch_set_state(GTK_SWITCH(widget), TRUE);
		}
		return TRUE;
	return TRUE;
}

//called when user clicks on the output switch in the grid
static gboolean button_press_event_output( GtkWidget *widget, GdkEventButton *event, cairo_t *cr) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gtk_fixed_move(GTK_FIXED(fixed),widget, gx-506, gy-176);			
			printf("%s\n",gtk_widget_get_name(widget));
			if(s == 5){
				printf("%s connected to output\n",gtk_widget_get_name(widget));
				s = 0;
			}	
			if(gtk_switch_get_state(GTK_SWITCH(widget)) == TRUE){
				gtk_switch_set_state(GTK_SWITCH(widget), FALSE);
			}
			else
	    		if(gtk_switch_get_state(GTK_SWITCH(widget)) == FALSE){
					gtk_switch_set_state(GTK_SWITCH(widget), TRUE);	
				}
		}
	}
	else
		if (event->type == GDK_BUTTON_PRESS){
			if(gtk_switch_get_state(GTK_SWITCH(widget)) == TRUE)
					gtk_switch_set_state(GTK_SWITCH(widget), FALSE);
			else
	    		if(gtk_switch_get_state(GTK_SWITCH(widget)) == FALSE)
						gtk_switch_set_state(GTK_SWITCH(widget), TRUE);	
		}
		return TRUE;	
	return TRUE;
}

static gboolean button_press_event_toggle_input(GtkWidget *widget, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gtk_fixed_move(GTK_FIXED(fixed),widget, gx-566, gy-176);
			printf("toggle %s\n",gtk_widget_get_name(widget));
			switch(s){
					case 1: printf("%s connected to port 1\n",gtk_widget_get_name(widget));					
							s = 0;			
							break;
				
					case 2: printf("%s connected to port 2\n",gtk_widget_get_name(widget));							
							s = 0;
							break;
			    
					case 3: printf("%s connected to port 3\n",gtk_widget_get_name(widget));					
							s = 0;
							break;
							
					case 4: printf("%s connected to port 4\n",gtk_widget_get_name(widget));
							s = 0;
							break;
							
					case 5: printf("%s connected to output\n",gtk_widget_get_name(widget));
							s = 0;
							break;
			}
					
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),FALSE);
			
			else
	    		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == FALSE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
			
		}
	}
	else 
		if (event->type == GDK_BUTTON_PRESS){
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),FALSE);
			else
	    		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == FALSE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
		return TRUE;
		}
	return TRUE;
}

static gboolean button_press_event_toggle_output(GtkWidget *widget, GdkEventButton *event) {
	if(start == 0){
		if (event->type == GDK_BUTTON_PRESS){
			gtk_fixed_move(GTK_FIXED(fixed),widget, gx-506, gy-176);
			printf("%s\n",gtk_widget_get_name(widget));
			if(s == 5){
				printf("%s connected to output\n",gtk_widget_get_name(widget));
				s = 0;
			}	
					
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),FALSE);
			
			else
	    		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == FALSE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
			
		}
	}
	else 
		if (event->type == GDK_BUTTON_PRESS){
			if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),FALSE);
			else
	    		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == FALSE)
					gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
		return TRUE;
		}
	return TRUE;
}	

//called when user moves a widget (excluding switches) in the grid.
static gboolean motion_notify_event_1( GtkWidget *widget, GdkEventMotion *event, cairo_t *cr) {
    
	int x, y;
	GdkModifierType state;
	gdk_window_get_device_position ( event->window, event->device, &x, &y, &state );
	if(start == 0){
		if (state == GDK_BUTTON1_MASK) {
			gtk_fixed_move(GTK_FIXED(fixed), widget, x, y);
		}
	}
	else 
		return TRUE;
	return TRUE;
}

//goocanvas path of input wire
static void inwire(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L90,10","stroke-color","black",NULL);	
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(inputwire), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

//goocanvas path of output wire
static void outwire(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L90,10","stroke-color","black",NULL);	
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(outputwire), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}


static void inputswitch(GtkWidget *widget, gpointer data)
{
	widget = gtk_switch_new();
	gtk_widget_set_name(widget,switchnames[n]);
	n++;
	printf("%d\n",n);
	gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	gtk_fixed_put(GTK_FIXED(fixed),widget,1,1);
	g_signal_connect (G_OBJECT(widget), "button_press_event", G_CALLBACK(button_press_event_input), NULL);
	g_signal_connect (G_OBJECT(widget), "motion_notify_event", G_CALLBACK(motion_notify_event_1), NULL);
	gtk_widget_show(widget);
}

static void outputswitch(GtkWidget *widget, gpointer data)
{
	widget = gtk_switch_new();
	gtk_widget_set_name(widget,switchnames[n]);
	n++;
	printf("%d\n",n);
	gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	gtk_fixed_put(GTK_FIXED(fixed),widget,1,1);
	g_signal_connect (G_OBJECT(widget), "button_press_event", G_CALLBACK(button_press_event_output), NULL);
	g_signal_connect (G_OBJECT(widget), "motion_notify_event", G_CALLBACK(motion_notify_event_1), NULL);
	gtk_widget_show(widget);
}

static void addinputtoggle(GtkWidget *widget, gpointer data)
{
	widget = gtk_toggle_button_new_with_label("Input");
	gtk_widget_set_name(widget,togglenames[m]);
	m++;
	printf("%d\n",m);
	gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (GTK_TOGGLE_BUTTON(widget), "button_press_event", G_CALLBACK(button_press_event_toggle_input), NULL);
	g_signal_connect (GTK_TOGGLE_BUTTON(widget), "motion_notify_event", G_CALLBACK(motion_notify_event_1), NULL);
	gtk_fixed_put(GTK_FIXED(fixed),widget,1,1);
	gtk_widget_show(widget);
}

static void addoutputtoggle(GtkWidget *widget, gpointer data)
{
	widget = gtk_toggle_button_new_with_label("Output");
	gtk_widget_set_name(widget,togglenames[m]);
	m++;
	printf("%d\n",m);
	gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (GTK_TOGGLE_BUTTON(widget), "button_press_event",G_CALLBACK(button_press_event_toggle_output), NULL);
	g_signal_connect (GTK_TOGGLE_BUTTON(widget), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
	gtk_fixed_put(GTK_FIXED(fixed),widget,1,1);
	gtk_widget_show(widget);
}

static void bulbdisplay(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
	GooCanvasItem *path = goo_canvas_path_new (root,"M40,40 L40,30 L35,30 L35,25 C35,25 10,12.5 40,0 M40,0 C40,0 70,12.5 45,25 M45,25 L45,30 L40,30 M45,25 L35,25","stroke-color","black",NULL);	
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}


typedef struct gate{
	int in;
	int *nos;
	int output;
}gate;
	
int AND(int *p,int n){
	int i,opt;
	for(i = 0;i < n; i++){
		opt = (p[i] && p[i+1]);
		p[i+1] = opt;	
	}
	return p[n-1];
}

int OR(int *p,int n){
	int i,opt;
	for(i = 0;i < n; i++){
		opt = (p[i] || p[i+1]);
        	p[i+1] = opt;
	}
	return p[n-1];
}			    

int NOT(int n){
	int output;
	if (n == 0)
		output = 1;
	else
		output = 0;
	return output;
}

int NAND(int *p,int n){
	return NOT(AND(p,n));
}

int NOR(int *p,int n){
	return NOT(OR(p,n));
}

int XOR(int *p,int n){
	int i,opt,count = 0;
	for(i = 0;i < n; i++){
		if(p[i] == 1)
			count++;
	}
	if(count % 2 == 0)
		opt = 0;
	else
		opt = 1;
	return opt;
}

int XNOR(int *p,int n){
	return NOT(XOR(p,n));
}


static void and(GtkWidget *widget, gpointer data)
{ 
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 90, 90);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 90, 90);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,0,0);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 L85,40", "stroke-color","black",NULL);
  	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);

	//create and gate node and add data to it
/*
	gate and;
	and.in = 2;
	and.nos = (int *)malloc(sizeof(int) * 2);
	and.output = AND(and.nos,and.in);
*/
}

static void and3(GtkWidget *widget, gpointer data)
{ 
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L20,10 L20,0 C20,0 120,40 20,80 M20,80 L20,0 M0,40 L20,40 M0,70 L20,70 M65,40 L85,40", "stroke-color","black",NULL);
  	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*			
	gate and;
	and.in = 3;
	and.nos = (int *)malloc(sizeof(int) * 3);
	and.output = AND(and.nos,and.in);
*/
}

static void and4(GtkWidget *widget, gpointer data)
{ 
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 150, 150);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 150, 150);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,5 L20,5 L20,0 C20,0 120,50 20,100 M20,100 L20,0 M0,35 L20,35 M0,65 L20,65 M65,50 L85,50 M0,95 L20,95", "stroke-color","black",NULL); 			
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*		
	gate and;
	and.in = 4;
	and.nos = (int *)malloc(sizeof(int) * 4);
	and.output = AND(and.nos,and.in);
*/		
}

static void or(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 L85,40","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*			
	gate or;
	or.in = 2;
	or.nos = (int *)malloc(sizeof(int) * 2);
	or.output = OR(or.nos,or.in);
*/
}
static void or3(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L25,10 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,40 L25,40 M65,40 L85,40 M0,70 L25,70","stroke-color","black",NULL);
    gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate or;
	or.in = 3;
	or.nos = (int *)malloc(sizeof(int) * 3);
	or.output = OR(or.nos,or.in);
*/
}

static void or4(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,5 L25,5 M20,0 C20,0 40,50 20,100 M20,0 C20,0 120,50 20,100 M0,35 L25,35 M65,50 L85,50 M0,65 L20,65 M0,95 L20,95","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate or;
	or.in = 4;
	or.nos = (int *)malloc(sizeof(int) * 4);
	or.output = OR(or.nos,or.in);
*/
}

static void not(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 L40,20 L20,40 L20,20 M40,20 L60,20","stroke-color","black",NULL);
  	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate not;
	not.in = 1;
	not.nos = (int *)malloc(sizeof(int));
	not.output = NOT(not.nos[0]);
*/
}

static void nand(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40", "stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*			
	gate nand;
	nand.in = 2;
	nand.nos = (int *)malloc(sizeof(int) * 2);
	nand.output = NAND(nand.nos,nand.in);
*/
}

static void nand3(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L20,10 L20,0 C20,0 120,40 20,80 M20,80 L20,10 M0,40 L20,40 M0,70 L20,70 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40", "stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*			
	gate nand;
	nand.in = 3;
	nand.nos = (int *)malloc(sizeof(int) * 3);
	nand.output = NAND(nand.nos,nand.in);
*/
}

static void nand4(GtkWidget *widget, gpointer data)
{ 
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,5 L20,5 L20,0 C20,0 120,50 20,100 M20,100 L20,0 M0,35 L20,35 M0,65 L20,65 M65,50 L85,50 M0,95 L20,95 M65,50 C65,50 70,45 75,50 M75,50 C75,50 70,55 65,50 M75,50 L85,50", "stroke-color","black",NULL); 			
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate nand;
	nand.in = 4;
	nand.nos = (int *)malloc(sizeof(int) * 4);
	nand.output = NAND(nand.nos,nand.in);
*/
}


static void nor(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate nor;
	nor.in = 2;
	nor.nos = (int *)malloc(sizeof(int) * 2);
	nor.output = NOR(nor.nos,nor.in);
*/
}

static void nor3(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L25,10 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,40 L25,40 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40 M0,70 L25,70","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*	
	gate nor;
	nor.in = 3;
	nor.nos = (int *)malloc(sizeof(int) * 3);
	nor.output = NOR(nor.nos,nor.in);
*/
}

static void nor4(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,5 L20,5 M20,0 C20,0 40,50 20,100 M20,0 C20,0 120,50 20,100 M0,35 L20,35 M0,65 L20,65 M0,95 L20,95 M65,50 C65,50 70,45 75,50 M75,50 C75,50 70,55 65,50 M75,50 L85,50","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*		
	gate nor;
	nor.in = 4;
	nor.nos = (int *)malloc(sizeof(int) * 4);
	nor.output = NOR(nor.nos,nor.in);
*/
}

static void xor(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 L85,40","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate xor;
	xor.in = 2;
	xor.nos = (int *)malloc(sizeof(int) * 2);
	xor.output = XOR(xor.nos,xor.in); 
*/
}

static void xor3(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L20,10 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,40 L20,40 M65,40 L85,40 M0,70 L20,70","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*	
	gate xor;
	xor.in = 3;
	xor.nos = (int *)malloc(sizeof(int) * 3);
	xor.output = XOR(xor.nos,xor.in);
*/ 
}

static void xor4(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M15,0 C15,0 35,50 15,100 M0,5 L25,5 M20,0 C20,0 40,50 20,100 M20,0 C20,0 120,50 20,100 M0,35 L25,35 M65,50 L85,50 M0,65 L20,65 M0,95 L20,95","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate xor;
	xor.in = 4;
	xor.nos = (int *)malloc(sizeof(int) * 4);
	xor.output = XOR(xor.nos,xor.in); 
*/
}

static void xnor(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*
	gate xnor;
	xnor.in = 2;
	xnor.nos = (int *)malloc(sizeof(int) * 2);
	xnor.output = XNOR(xnor.nos,xnor.in); 
*/
}

static void xnor3(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
	GooCanvasItem *path = goo_canvas_path_new (root,"M0,10 L20,10 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,40 L20,40 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L85,40 M0,70 L20,70","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_2), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*		
	gate xnor;
	xnor.in = 3;
	xnor.nos = (int *)malloc(sizeof(int) * 3);
	xnor.output = XNOR(xnor.nos,xnor.in); 
*/
}

static void xnor4(GtkWidget *widget, gpointer data)
{
	canvas = goo_canvas_new ();
  	gtk_widget_set_size_request (canvas, 120, 120);
  	goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  	gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  	gtk_widget_show (canvas);
	root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  	GooCanvasItem *path = goo_canvas_path_new (root,"M15,0 C15,0 35,50 15,100 M0,5 L25,5 M20,0 C20,0 40,50 20,100 M20,0 C20,0 120,50 20,100 M0,35 L25,35 M0,65 L20,65 M0,95 L20,95 M65,50 C65,50 70,45 75,50 M75,50 C75,50 70,55 65,50 M75,50 L85,50 ","stroke-color","black",NULL);
	gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
	g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_3), NULL);
	g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
/*			
	gate xnor;
	xnor.in = 4;
	xnor.nos = (int *)malloc(sizeof(int) * 4);
	xnor.output = XNOR(xnor.nos,xnor.in);  
*/
}


static void destroywindow(GtkWidget *widget,GtkWindow *win){
	gtk_widget_hide(window1);			
}

static void andwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "AND GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(and),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(and3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);
			
	four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(and4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);
			
  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

static void orwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "OR GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(or),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(or3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);
			
	four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(or4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);

  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

static void nandwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "NAND GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(nand),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(nand3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);
			
	four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(nand4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);

  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

static void norwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "NOR GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(nor),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(nor3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);
			
	four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(nor4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);

  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

static void xorwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "XOR GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(xor),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(xor3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);

    four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(xor4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);

  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

static void xnorwindow(GtkWidget *widget,gpointer data)
{
	window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	gtk_window_set_title(GTK_WINDOW(window1), "XNOR GATE");
  	gtk_window_set_default_size (GTK_WINDOW (window1), 150, 150);
  	gtk_container_set_border_width(GTK_CONTAINER(window1), 10);
  	gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
  			
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window1),box);
  			
  	combolabel = gtk_label_new("Select the number of inputs:");
  	gtk_box_pack_start(GTK_BOX(box),combolabel,TRUE,TRUE,10);
  			
  	two = gtk_button_new_with_label("Two");
  	gtk_box_pack_start(GTK_BOX(box),two,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(xnor),NULL);
  	g_signal_connect(GTK_BUTTON(two),"clicked",G_CALLBACK(destroywindow),NULL);
  			
    three = gtk_button_new_with_label("Three");
  	gtk_box_pack_start(GTK_BOX(box),three,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(xnor3),NULL);
	g_signal_connect(GTK_BUTTON(three),"clicked",G_CALLBACK(destroywindow),NULL);
		
	four = gtk_button_new_with_label("Four");
  	gtk_box_pack_start(GTK_BOX(box),four,TRUE,TRUE,10);
  	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(xnor4),NULL);
	g_signal_connect(GTK_BUTTON(four),"clicked",G_CALLBACK(destroywindow),NULL);

  	gtk_widget_show(box);
    gtk_widget_show(combolabel);
  	gtk_widget_show_all(window1);
  			
}

void aboutdialog(GtkWidget *widget, gpointer data)
{
	window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window2), "ABOUT");
  	gtk_window_set_default_size (GTK_WINDOW (window2), 100, 100);
  	gtk_container_set_border_width(GTK_CONTAINER(window2), 10);
  	gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
  	
  	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  	gtk_container_add(GTK_CONTAINER(window2),box);
  	
  	l1 = gtk_label_new("LOGIC GATE SIMULATOR v0.01");
  	gtk_box_pack_start(GTK_BOX(box),l1,TRUE,TRUE,10);
  	
  	l2 = gtk_label_new("Akash Patil\n111508005");
  	gtk_box_pack_start(GTK_BOX(box),l2,TRUE,TRUE,10);
  	
  	gtk_widget_show(box);
    gtk_widget_show(l1);
    gtk_widget_show(l2);
  	gtk_widget_show_all(window2);
}


//-------Translucent background window-------
gboolean supports_alpha = FALSE;
static void screen_changed(GtkWidget *widget, GdkScreen *old_screen, gpointer userdata)
{
    //To check if the display supports alpha channels, get the visual 
    GdkScreen *screen = gtk_widget_get_screen(widget);
    GdkVisual *visual = gdk_screen_get_rgba_visual(screen);

    if (!visual)
    {
        printf("Your screen does not support alpha channels!\n");
        visual = gdk_screen_get_system_visual(screen);
        supports_alpha = FALSE;
    }
    else
    {
        printf("Your screen supports alpha channels!\n");
        supports_alpha = TRUE;
    }

    gtk_widget_set_visual(widget, visual);
}

static gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer userdata)
{
   cairo_t *new_cr = gdk_cairo_create(gtk_widget_get_window(widget));

    if (supports_alpha)
    {
        cairo_set_source_rgba (new_cr, 1.0, 0.2, 0.2, 0.6); /* transparent */
    }
    else
    {
        cairo_set_source_rgb (new_cr, 1.0, 1.0, 1.0); /* opaque white */
    }

    /* draw the background */
    cairo_set_operator (new_cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint (new_cr);

    cairo_destroy(new_cr);

    return FALSE;
}

static void cleargrid(GtkWidget *widget)
{
	gtk_widget_destroy(fixed);
	fixed = gtk_fixed_new();
	gtk_paned_pack2(GTK_PANED(vpaned),fixed,TRUE,TRUE);
	gtk_widget_show(fixed);
	gtk_widget_show(vpaned);
} 

int main(int argc, char *argv[]) {

  if(argc == 1){
  		goto loop;
  }
  
  if(strcmp(argv[1],"-h") == 0){
  		printf("--------------------------\nUSAGE:\n\nInitially,to compile the program, we need to install three libraries namely gtk3.0, goocanvas2.0 and cairo  using sudo-apt command. After the three libraries have been installed, compile the program using the makefile. The application window consists of a transparent background which will display only if your system supports alpha channels.\n---------------------------\n");
  		return 0;
  }		
  
  loop:	
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Logic Gate Simulator");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  g_signal_connect(GTK_WINDOW(window),"button_press_event",G_CALLBACK(button_press_event_1),NULL);
  
  GtkSettings *default_settings = gtk_settings_get_default();
  g_object_set(default_settings, "gtk-button-images", TRUE, NULL); 

  
  //-----------background colour
  gtk_widget_set_app_paintable(window, TRUE);

  g_signal_connect(G_OBJECT(window), "draw", G_CALLBACK(draw), NULL);
  g_signal_connect(G_OBJECT(window), "screen-changed", G_CALLBACK(screen_changed), NULL);

  gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
  gtk_window_set_decorated(GTK_WINDOW(window),TRUE);
  screen_changed(window, NULL, NULL);
  //----------
  
  vpaned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add(GTK_CONTAINER(window),vpaned);
  gtk_paned_set_position(GTK_PANED(vpaned),175);
  gtk_widget_show(vpaned);
  
  grid = gtk_grid_new();
  gtk_grid_set_column_spacing (GTK_GRID (grid), 10);
  gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
  
  fixed = gtk_fixed_new();
  
  gtk_paned_pack1(GTK_PANED(vpaned),grid,TRUE,TRUE);
  
  gtk_paned_pack2(GTK_PANED(vpaned),fixed,TRUE,TRUE);

  menu_bar = gtk_menu_bar_new();
  file_menu = gtk_menu_new();
  help_menu = gtk_menu_new();
  options_menu = gtk_menu_new();
  
  menu_item=gtk_menu_item_new_with_label("File");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

  menu_item=gtk_menu_item_new_with_label("Help");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),help_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);
  
  menu_item=gtk_menu_item_new_with_label("Options");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),options_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

  menu_item=gtk_menu_item_new_with_label("New");
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item),"activate",G_CALLBACK(cleargrid),NULL);

  menu_item=gtk_menu_item_new_with_label("Exit");
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",G_CALLBACK(gtk_main_quit), NULL);

  menu_item=gtk_menu_item_new_with_label("About");
  gtk_menu_shell_append(GTK_MENU_SHELL(help_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",G_CALLBACK(aboutdialog), NULL);

  menu_item=gtk_menu_item_new_with_label("Start");
  gtk_menu_shell_append(GTK_MENU_SHELL(options_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",G_CALLBACK(startoption), NULL);

  menu_item=gtk_menu_item_new_with_label("Stop");
  gtk_menu_shell_append(GTK_MENU_SHELL(options_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",G_CALLBACK(stopoption), NULL);

  gtk_grid_attach(GTK_GRID(grid),menu_bar,0,0,2,1);
  
  label = gtk_label_new("Input Controls:");
  PangoFontDescription *font_desc = pango_font_description_from_string ("sans 15");
  gtk_widget_modify_font (label, font_desc);
  pango_font_description_free (font_desc);
  GdkColor color;
  gdk_color_parse ("white", &color);
  gtk_widget_modify_fg (label, GTK_STATE_NORMAL, &color);
  gtk_grid_attach(GTK_GRID(grid),label,0,1,2,1);
  
  switcherbtn = gtk_button_new_with_label("Switch");
  gtk_grid_attach(GTK_GRID(grid),switcherbtn,0,2,1,1);
  g_signal_connect(GTK_BUTTON(switcherbtn),"clicked", G_CALLBACK(inputswitch),NULL);  
  
  toggle1 = gtk_button_new_with_label("Toggle");
  gtk_grid_attach(GTK_GRID(grid),toggle1,1,2,1,1);
  g_signal_connect(GTK_BUTTON(toggle1),"clicked", G_CALLBACK(addinputtoggle),NULL);  

  label1 = gtk_label_new("Output Controls:");
  PangoFontDescription *font_desc1 = pango_font_description_from_string ("sans 15");
  gtk_widget_modify_font (label1, font_desc1);
  pango_font_description_free (font_desc1);
  GdkColor color1;
  gdk_color_parse ("white", &color1);
  gtk_widget_modify_fg (label1, GTK_STATE_NORMAL, &color1);
  gtk_grid_attach(GTK_GRID(grid),label1,0,3,2,1);

  bulb = gtk_button_new_with_label("Toggle");
  gtk_grid_attach(GTK_GRID(grid),bulb,1,4,1,1);
  g_signal_connect(GTK_BUTTON(bulb),"clicked", G_CALLBACK(addoutputtoggle),NULL); 

  toggle2 = gtk_button_new_with_label("Switch");
  gtk_grid_attach(GTK_GRID(grid),toggle2,0,4,1,1);
  g_signal_connect(GTK_BUTTON(toggle2),"clicked", G_CALLBACK(outputswitch),NULL);  

  label2 = gtk_label_new("Gates:");
  PangoFontDescription *font_desc2 = pango_font_description_from_string ("sans 15");
  gtk_widget_modify_font (label2, font_desc2);
  pango_font_description_free (font_desc2);
  GdkColor color2;
  gdk_color_parse ("white", &color2);
  gtk_widget_modify_fg (label2, GTK_STATE_NORMAL, &color2);
  gtk_grid_attach(GTK_GRID(grid),label2,0,5,2,1);
  
  And = gtk_button_new_with_label("And");
  gtk_grid_attach(GTK_GRID(grid),And,0,6,1,1);
  g_signal_connect(GTK_BUTTON(And),"clicked", G_CALLBACK(andwindow),NULL);  
  
  Or = gtk_button_new_with_label("Or");
  gtk_grid_attach(GTK_GRID(grid),Or,1,6,1,1);
  g_signal_connect(GTK_BUTTON(Or),"clicked", G_CALLBACK(orwindow),NULL); 
  
  Not = gtk_button_new_with_label("Not");
  gtk_grid_attach(GTK_GRID(grid),Not,0,7,1,1);
  g_signal_connect(GTK_BUTTON(Not),"clicked", G_CALLBACK(not),NULL);   

  Nand = gtk_button_new_with_label("Nand");
  gtk_grid_attach(GTK_GRID(grid),Nand,1,7,1,1);
  g_signal_connect(GTK_BUTTON(Nand),"clicked", G_CALLBACK(nandwindow),NULL);  
  
  Nor = gtk_button_new_with_label("Nor");
  gtk_grid_attach(GTK_GRID(grid),Nor,0,8,1,1);
  g_signal_connect(GTK_BUTTON(Nor),"clicked", G_CALLBACK(norwindow),NULL); 
  
  Xor = gtk_button_new_with_label("Xor");
  gtk_grid_attach(GTK_GRID(grid),Xor,1,8,1,1);
  g_signal_connect(GTK_BUTTON(Xor),"clicked", G_CALLBACK(xorwindow),NULL);   
  
  Xnor = gtk_button_new_with_label("Xnor");
  gtk_grid_attach(GTK_GRID(grid),Xnor,0,9,1,1);	
  g_signal_connect(GTK_BUTTON(Xnor),"clicked", G_CALLBACK(xnorwindow),NULL);  
  
  label3 = gtk_label_new("Wires:");
  PangoFontDescription *font_desc3 = pango_font_description_from_string ("sans 15");
  gtk_widget_modify_font (label3, font_desc3);
  pango_font_description_free (font_desc3);
  GdkColor color3;
  gdk_color_parse ("white", &color3);
  gtk_widget_modify_fg (label3, GTK_STATE_NORMAL, &color3);
  gtk_grid_attach(GTK_GRID(grid),label3,0,10,2,1);
  
  wirebtn1 = gtk_button_new_with_label("Inwire");
  gtk_grid_attach(GTK_GRID(grid),wirebtn1,0,11,1,1);
  g_signal_connect(GTK_BUTTON(wirebtn1),"clicked", G_CALLBACK(inwire),NULL);  

  wirebtn2 = gtk_button_new_with_label("Outwire");
  gtk_grid_attach(GTK_GRID(grid),wirebtn2,1,11,1,1);
  g_signal_connect(GTK_BUTTON(wirebtn2),"clicked", G_CALLBACK(outwire),NULL);  
  
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
  gtk_widget_show_all(window);
  
  gtk_main();
  return 0;
}


