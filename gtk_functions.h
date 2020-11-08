//
// Created by Unknow on 08/11/2020.
//

#ifndef GTK_TP_GTK_FUNCTIONS_H
#define GTK_TP_GTK_FUNCTIONS_H

#include <gtk/gtk.h>
#include <stdio.h>


//Construire GTK depuis le fichier glade
static GtkBuilder *builder;

typedef struct {
    GtkWindow *window;
    GtkEntry *entry_number_1;
    GtkEntry *entry_number_2;
    GtkComboBoxText *combo_operator;
    GtkLabel *label_result;
    GtkButton *button_calcul;
    GtkLabel *label_statut;
} App_widgets;

static App_widgets *widgets;

///////////////////////////////////////////////////////////////////////////////////////
#if defined(__WIN32) || defined(WIN32)

G_MODULE_EXPORT void on_button_calcul_clicked();

#endif
///////////////////////////////////////////////////////////////////////////////////////

void onDestroy();

void startGTK(int *argc, char ***argv, char *gladeFile);

void connectWidgets();


#endif //GTK_TP_GTK_FUNCTIONS_H
