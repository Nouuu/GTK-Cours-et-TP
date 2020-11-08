#include <stdlib.h>
#include "gtk_functions.h"

int main(int argc, char **argv) {
#ifdef __unix__
    setenv("DISPLAY", "127.0.0.1:0", 1);
#endif
    char *gladeFilePath = strdup("./gui_files/gui.glade");

    startGTK(&argc, &argv, gladeFilePath);

    free(gladeFilePath);
}