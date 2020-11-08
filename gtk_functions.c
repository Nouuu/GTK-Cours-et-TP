//
// Created by Unknow on 08/11/2020.
//

#include "gtk_functions.h"

//////////////////////////////////////////////////////////////////////////////////////////
void on_button_calcul_clicked() {
    printf("Number 1 : %s\n", gtk_entry_get_text(widgets->entry_number_1));
    printf("Number 2 : %s\n", gtk_entry_get_text(widgets->entry_number_2));
    printf("Operator : %s\n", gtk_combo_box_text_get_active_text(widgets->combo_operator));
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
    printf("Closing app\n");
}

void connectWidgets() {
    widgets = g_slice_new(App_widgets);

    widgets->window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
    widgets->entry_number_1 = GTK_ENTRY(gtk_builder_get_object(builder, "entry_number_1"));
    widgets->entry_number_2 = GTK_ENTRY(gtk_builder_get_object(builder, "entry_number_2"));
    widgets->combo_operator = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "combo_operator"));
    widgets->label_result = GTK_LABEL(gtk_builder_get_object(builder, "label_result"));
    widgets->button_calcul = GTK_BUTTON(gtk_builder_get_object(builder, "button_calcul"));
    widgets->label_statut = GTK_LABEL(gtk_builder_get_object(builder, "label_statut"));
}

void onDestroy() {
    gtk_main_quit();
}