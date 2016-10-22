#include <gtk/gtk.h>
#include <stdio.h>
//#import  <objc/runtime.h>
#include <cairo.h>
#include <goocanvas.h>
#include <string.h>
#include <stdlib.h>

  GtkWidget *window, *window1;
  GtkWidget *box;
  GtkWidget *grid, *grid1;
  GtkWidget *switcherbtn, *toggle1, *toggle2, *bulb, *And, *Or, *Not, *Nand, *Nor, *Xor, *Xnor;
  GtkWidget *vpaned;
  GtkWidget *frame;
  GtkWidget *combo;
  GtkWidget *label;
  GtkWidget *label1, *label2, *combolabel;
  GtkWidget *switcher1;
  GtkWidget *switcher2;
  GtkWidget *vseperator;
  GtkWidget *file_menu, *help_menu, *menu_bar, *root_menu, *menu_item;
  GtkWidget *fixed;
  GtkWidget *toggleinput, *toggleoutput;
  GtkWidget *canvas;
  GtkWidget *okaybtn;
  GooCanvasItem *root;
  GtkWidget *two, *three, *four;
 int sx, sy, offsetx, offsety, px,py, maxx, maxy;
  
/* const gint Sensitivity = 10;
	
inline static int RoundDownToMultiple(const int i, const int m)
{
	return i/m*m;
}
inline static int RoundToNearestMultiple(const int i, const int m)
{
	if (i % m > (double)m / 2.0d)
		return (i/m+1)*m;
	return i/m*m;
}

static gboolean button_press_event_1( GtkWidget *w, GdkEventButton *event )
{
	if (event->button == 1) {
		GtkWidget *p = w->parent;
		// offset == distance of parent widget from edge of screen ...
		gdk_window_get_position(p->window, &offsetx, &offsety);
		// plus distance from pointer to edge of widget
		offsetx += (int)event->x;
		offsety += (int)event->y;
		// maxx, maxy both relative to the parent
		// note that we're rounding down now so that these max values don't get
		// rounded upward later and push the widget off the edge of its parent.
		maxx = RoundDownToMultiple(p->get_preferred_width() - w->get_preferred_width(), Sensitivity);
		maxy = RoundDownToMultiple(p->get_preferred_height() - w->get_preferred_height(), Sensitivity);
	}
	return TRUE;
}

static gboolean motion_notify_event_1( GtkWidget *widget, GdkEventMotion *event )
{
	// x_root,x_root relative to screen
	// x,y relative to parent (fixed widget)
	// px,py stores previous values of x,y

	// get starting values for x,y
	int x = (int)event->x_root - offsetx;
	int y = (int)event->y_root - offsety;
	// make sure the potential coordinates x,y:
	//   1) will not push any part of the widget outside of its parent container
	//   2) is a multiple of Sensitivity
	x = RoundToNearestMultiple(Max(Min(x, maxx), 0), Sensitivity);
	y = RoundToNearestMultiple(Max(Min(y, maxy), 0), Sensitivity);
	if (x != px || y != py) {
		px = x;
		py = y;
		gtk_fixed_move(GTK_FIXED(fixed), widget, x, y);
	}
	return TRUE;
}*/
static gboolean button_press_event_2( GtkWidget *widget, GdkEventButton *event, cairo_t *cr) {
	if (event->button == 1){
		sx=(int)event->x;
		sy=(int)event->y;
		if(gtk_switch_get_state(GTK_SWITCH(widget)) == TRUE)
				gtk_switch_set_state(GTK_SWITCH(widget), FALSE);
		else
	    if(gtk_switch_get_state(GTK_SWITCH(widget)) == FALSE)
				gtk_switch_set_state(GTK_SWITCH(widget), TRUE);
				
		}
	return TRUE;
}

static gboolean button_press_event_1( GtkWidget *w, GdkEventButton *event) {
	if (event->button == 1){
		sx=(int)event->x;
		sy=(int)event->y;
		printf("%d %d\n",sx,sy);
	}
	return TRUE;
}

static gboolean motion_notify_event_1( GtkWidget *widget, GdkEventMotion *event, cairo_t *cr) {
    
	int x, y;
	
	GdkModifierType state;
	gdk_window_get_device_position ( event->window, event->device, &x, &y, &state );
	if (state & GDK_BUTTON1_MASK) {
		//printf(" %i , %i \n", x-sx, y-sy);
		gtk_fixed_move(GTK_FIXED(fixed),widget,x-sx, y-sy);
	}

	return TRUE;
}

static void addswitch(GtkWidget *widget, gpointer data)
{
			widget = gtk_switch_new();
			gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			//gtk_switch_set_active(GTK_SWITCH(widget),TRUE);
			gtk_fixed_put(GTK_FIXED(fixed),widget,1,1);
			g_signal_connect (G_OBJECT(widget), "button_press_event", G_CALLBACK(button_press_event_2), NULL);
			g_signal_connect (G_OBJECT(widget), "motion_notify_event", G_CALLBACK(motion_notify_event_1), NULL);
			gtk_widget_show(widget);
}

static void addinputtoggle(GtkWidget *widget, gpointer data)
{
			widget = gtk_toggle_button_new_with_label("Input");
			gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (GTK_TOGGLE_BUTTON(widget), "button_press_event", G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (GTK_TOGGLE_BUTTON(widget), "motion_notify_event", G_CALLBACK(motion_notify_event_1), NULL);
			//gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
			gtk_fixed_put(GTK_FIXED(fixed),widget,5,1);
			gtk_widget_show(widget);
}

static void addoutputtoggle(GtkWidget *widget, gpointer data)
{
			widget = gtk_toggle_button_new_with_label("Output");
			//gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
			gtk_widget_set_events(widget, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (GTK_TOGGLE_BUTTON(widget), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (GTK_TOGGLE_BUTTON(widget), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
			//gtk_grid_attach(GTK_GRID(grid1),widget,3,4,1,1);
			gtk_widget_show(widget);
			//gtk_widget_show(grid1);
}

static void bulbdisplay(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,3,5,1,1);
  			//gtk_widget_show(grid1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
			GooCanvasItem *path = goo_canvas_path_new (root,"M40,40 L40,30 L35,30 L35,25 C35,25 10,12.5 40,0 M40,0 C40,0 70,12.5 45,25 M45,25 L45,30 L40,30 M45,25 L35,25","stroke-color","black",NULL);	
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void and(GtkWidget *widget, gpointer data)
{ 
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 90, 90);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 90, 90);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,5,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 L85,40", "stroke-color","black",NULL);
  			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void and3(GtkWidget *widget, gpointer data)
{ 
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,6,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 L85,40 M0,40 L20,40", "stroke-color","black",NULL);
  			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void and4(GtkWidget *widget, gpointer data)
{ 
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,6,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L20,16 L20,0 C20,0 120,40 20,80 M20,80 L20,0 M20,64 L0,64 M20,48 L0,48 M65,40 L85,40 M0,32 L20,32", "stroke-color","black",NULL); 			
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void or(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,7,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 L85,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void or3(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,8,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 L85,40 M0 M0,40 L20,40","stroke-color","black",NULL);
            gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void or4(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,8,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L25,16 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,32 L25,32 M65,40 L85,40 M0,48 L20,48 M0,64 L20,64","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);

}

static void not(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,9,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,40 L20,40 L20,0 L80,40 L20,80 L20,40 M80,40 L100,40","stroke-color","black",NULL);
  			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void nand(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,10,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40", "stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void nand3(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,11,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 L20,0 C20,0 120,40 20,80 M20,80 L20,60 L0,60 M20,60 L20,20 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,40 L20,40", "stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void nand4(GtkWidget *widget, gpointer data)
{ 
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,6,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L20,16 L20,0 C20,0 120,40 20,80 M20,80 L20,0 M20,64 L0,64 M20,48 L0,48 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,32 L20,32", "stroke-color","black",NULL); 			
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}


static void nor(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,12,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void nor3(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,13,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L25,20 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,60 L25,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,40 L25,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void nor4(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,8,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L25,16 M20,0 C20,0 40,20 20,80 M20,0 C20,0 120,40 20,80 M0,32 L25,32 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,48 L20,48 M0,64 L20,64","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xor(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,14,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 L85,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xor3(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,15,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 L85,40 M0,40 L20,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xor4(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,14,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L20,16 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,32 L20,32 M0,48 L20,48 M0,64 L20,64 M65,40 L85,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xnor(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,16,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xnor3(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,17,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,20 L20,20 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,60 L20,60 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,40 L20,40","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
}

static void xnor4(GtkWidget *widget, gpointer data)
{
			canvas = goo_canvas_new ();
  			gtk_widget_set_size_request (canvas, 120, 120);
  			goo_canvas_set_bounds (GOO_CANVAS (canvas), 0, 0, 120, 120);
  			//gtk_grid_attach(GTK_GRID(grid1),canvas,2,16,1,1);
  			//gtk_widget_show(grid1);
  			gtk_fixed_put(GTK_FIXED(fixed),canvas,5,1);
  			gtk_widget_show (canvas);
			root = goo_canvas_get_root_item (GOO_CANVAS (canvas));
  			GooCanvasItem *path = goo_canvas_path_new (root,"M0,16 L20,16 M15,0 C15,0 35,40 15,80 M20,0 C20,0 40,40 20,80 M20,0 C20,0 120,40 20,80 M0,32 L20,32 M65,40 C65,40 70,35 75,40 M75,40 C75,40 70,45 65,40 M75,40 L90,40 M0,48 L20,48 M0,64 L20,64","stroke-color","black",NULL);
			gtk_widget_set_events(canvas, GDK_EXPOSURE_MASK| GDK_LEAVE_NOTIFY_MASK| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK| GDK_POINTER_MOTION_HINT_MASK); 
			g_signal_connect (G_OBJECT(canvas), "button_press_event",G_CALLBACK(button_press_event_1), NULL);
			g_signal_connect (G_OBJECT(canvas), "motion_notify_event",G_CALLBACK(motion_notify_event_1), NULL);
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
  		printf("Usage:\n Initially,to compile the program, we need to install certain libraries like gtk3 and goocanvas.\nTo install the libraries,one way is to first install 'brew' (linuxbrew) command which basically allows user to install any c library and its dependencies. To install it, type the following command ' '.\n Now we need to install three libraries namely, 'gtk+3','goocanvas' and 'cairo'. Their dependencies will be automatically installed. To install gtk+3, type 'brew install gtk+3' and similarly for goocanvas type 'brew install goocanvas' and 'brew install cairo' for cairo. Alternatively, the three libraries can be also installed using sudo-apt but then their dependencies will have to be installed individually.\nAfter the two libraries have been installed, compile the program using the makefile. The application window consists of a transparent background which will display only if your system supports alpha channels.\n");
  		return 0;
  }		
  
  loop:	
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Logic Gate Simulator");
  gtk_window_set_default_size (GTK_WINDOW (window), 600, 400);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  
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
  
  menu_item=gtk_menu_item_new_with_label("File");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

  menu_item=gtk_menu_item_new_with_label("Help");
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),help_menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

  menu_item=gtk_menu_item_new_with_label("New");
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item),"activate",G_CALLBACK(cleargrid),NULL);

  menu_item=gtk_menu_item_new_with_label("Exit");
  gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",G_CALLBACK(gtk_main_quit), NULL);

  menu_item=gtk_menu_item_new_with_label("About");
  gtk_menu_shell_append(GTK_MENU_SHELL(help_menu),menu_item);

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
  g_signal_connect(GTK_BUTTON(switcherbtn),"clicked", G_CALLBACK(addswitch),NULL);  
  
  
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

  bulb = gtk_button_new_with_label("Bulb");
  gtk_grid_attach(GTK_GRID(grid),bulb,0,4,1,1);
  g_signal_connect(GTK_BUTTON(bulb),"clicked", G_CALLBACK(bulbdisplay),NULL); 

  toggle2 = gtk_button_new_with_label("Switch");
  gtk_grid_attach(GTK_GRID(grid),toggle2,1,4,1,1);
  g_signal_connect(GTK_BUTTON(toggle2),"clicked", G_CALLBACK(addswitch),NULL);  

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
 
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
  gtk_widget_show_all(window);
  
  gtk_main();
  return 0;
}


