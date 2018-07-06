#include <gnome.h>

int main(int argc,char *argv[]){
    GtkWidget *app;

    gnome_program_init("gnome1","1.0",MODULE,argc,argv,NULL);
    app = gnome_app_new("gnome1","Gnome Title");
    gtk_widget_show(app);
    gtk_main();

    return 0;
}
