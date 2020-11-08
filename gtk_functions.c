//
// Created by Unknow on 08/11/2020.
//

#include "gtk_functions.h"

//////////////////////////////////////////////////////////////////////////////////////////
void on_button_calcul_clicked() {
    process_operation();
}
//////////////////////////////////////////////////////////////////////////////////////////

void hide_statut_bar() {
    gtk_widget_hide((GtkWidget *) widgets->label_statut);
}

void show_statut_bar(const char *message) {
    gtk_label_set_text(widgets->label_statut, message);
    gtk_widget_show((GtkWidget *) widgets->label_statut);
}

void process_operation() {
    hide_statut_bar();
    if (validate_number(widgets->entry_number_1) && validate_number(widgets->entry_number_2)) {
        switch (gtk_combo_box_text_get_active_text(widgets->combo_operator)[0]) {
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            default:
                show_statut_bar("An error occured with operator");
                break;
        }
    } else {
        show_statut_bar("Wrong input !");
    }
}

int validate_number(GtkEntry *entry) {
    char *endPtr;

    strtod(gtk_entry_get_text(entry), &endPtr);
    if (endPtr == gtk_entry_get_text(entry)) {
        return 0;
    }
    return 1;
}

void startGTK(int *argc, char ***argv, char *gladeFile) {
    gtk_init(argc, argv);
    builder = gtk_builder_new_from_file(gladeFile);
    connectWidgets();

    g_signal_connect(widgets->window, "destroy", G_CALLBACK(onDestroy), NULL);

    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);

    gtk_widget_show_all((GtkWidget *) widgets->window);
    hide_statut_bar();

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