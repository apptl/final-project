#include "window.h"
#include <gtkmm.h>


int main(int argc,char* argv[])
{
Gtk::Main app(argc,argv);
main_menu w;
Gtk::Main::run(w);

return 0;
}