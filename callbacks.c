#include "callbacks.h"

void window1_destroy_cb(GtkObject *object) 
{
    gtk_main_quit();
}

void drawingarea1_expose_event_cb(GtkWidget *widget,GdkEventExpose* e, gpointer data)
{
    cairo_t* cr;
    cr = gdk_cairo_create(GTK_WIDGET(data)->window);
    if (page != NULL)
        poppler_page_render(page, cr);
    cairo_destroy(cr);
}

void spinbutton1_change_value_cb(GtkWidget *widget, GdkEventExpose* e, gpointer data)
{

}

