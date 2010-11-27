#include "interface.h"

GtkWidget* create_window1(void){

    /* get the current working directory for vte and pdf */
    getcwd(cpath,255);

    /* load the program user interface from Glade3 by GtkBuilder */
    GError* error = NULL;
    GtkBuilder* builder = gtk_builder_new ();
    if (!gtk_builder_add_from_file (builder, "thesiswp.gbuilder", &error))
    {
        g_warning ("Couldn't load builder file: %s", error->message) ;
        g_error_free (error);
    }

    /* load the UI elements */
    GtkWidget* window;          /* create and connect by glade */
    GtkWidget* vbox1;           /* create and connect by glade */

    GtkWidget* scrollwindow2;   /* add by hand */
    GtkWidget *vte;             /* add by hand */ 

    window        = GTK_WIDGET(gtk_builder_get_object (builder,"window1"));
    vbox1         = GTK_WIDGET(gtk_builder_get_object (builder,"vbox1"));
    //scrollwindow2 = GTK_WIDGET(gtk_builder_get_object (builder,"scrollwindow2"));


    // Hierachy
    // ------------------------
    //  -> vbox1
    //     -> scrollwindow2 
    //        -> vte 
    //

    /* vte instance creation */
    vte = vte_terminal_new(); 
    vte_terminal_set_background_transparent(VTE_TERMINAL(vte), FALSE);
    vte_terminal_fork_command(VTE_TERMINAL(vte), NULL, NULL, NULL, cpath, TRUE, TRUE,TRUE);
    vte_terminal_set_scroll_on_keystroke(VTE_TERMINAL (vte), TRUE); 
    //vte_terminal_set_scroll_on_output(VTE_TERMINAL (vte), TRUE); 




    /* scrollwindow2 for vte */
    scrollwindow2 = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(scrollwindow2), 5);  
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollwindow2), vte);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollwindow2), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);

    gtk_box_pack_start_defaults(GTK_BOX(vbox1), scrollwindow2);

    /* connect the signals in the interface */
    gtk_builder_connect_signals(builder,NULL);

    return window;
}