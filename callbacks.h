#include <stdio.h>
#include <gtk/gtk.h>
#include <poppler.h>

extern PopplerDocument* doc;
extern PopplerPage* page;

void window1_destroy_cb(GtkObject *object);
void drawingarea1_expose_event_cb(GtkWidget *widget,GdkEventExpose* e, gpointer data);
void spinbutton1_change_value_cb(GtkWidget *widget, GdkEventExpose* e, gpointer data);
