#include <stdlib.h>
#include "gtk_functions.h"

int main(int argc, char **argv) {
    char *gladeFilePath = strdup("gui_files/gui.glade");

    startGTK(&argc, &argv, gladeFilePath);

    free(gladeFilePath);
}