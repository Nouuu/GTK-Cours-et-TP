//
// Created by Unknow on 08/11/2020.
//

#include "gtk_functions.h"

//////////////////////////////////////////////////////////////////////////////////////////

void on_button_1_clicked() {
    const char *entry = gtk_entry_get_text(widgets->gtk_textfield);
    if (strlen(entry) > 0) {
        gtk_label_set_text(widgets->text, entry);
    }

}

//////////////////////////////////////////////////////////////////////////////////////////

void startGTK(int *argc, char ***argv, char *gladeFile) {
    gtk_init(argc, argv);
    builder = gtk_builder_new_from_file(gladeFile);
    connectWidgets();

    g_signal_connect(widgets->window, "destroy", G_CALLBACK(onDestroy), NULL);

    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);

    gtk_widget_show_all((GtkWidget *) widgets->window);

    gtk_main();

    g_slice_free(App_widgets, widgets);
}

void connectWidgets() {
    widgets = g_slice_new(App_widgets);

    widgets->window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
    widgets->button_1 = GTK_BUTTON(gtk_builder_get_object(builder, "button_1"));
    widgets->gtk_textfield = GTK_ENTRY(gtk_builder_get_object(builder, "gtk_textfield"));
    widgets->text = GTK_LABEL(gtk_builder_get_object(builder, "text"));
}

void onDestroy() {
    gtk_main_quit();
}