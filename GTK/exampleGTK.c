#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

/*  To install GTK:
    sudo apt-get install libgtk-3-dev
    To compile: 
    gcc `pkg-config --cflags gtk+-3.0` exampleGTK.c -o exampleGTK `pkg-config --libs gtk+-3.0`
 */
static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;

// Create GTK Application
static void activate(GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Debt Tracker");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
  gtk_widget_show_all (window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new ("gtk.debt.tracker", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
