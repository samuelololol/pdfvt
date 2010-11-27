#include <stdio.h>
#include <gtk/gtk.h>
#include <poppler.h>

#include "callbacks.h"
#include "interface.h"

char cpath[256];
PopplerDocument* doc;     /* pdf document */
PopplerPage* page;        /* shown page */
