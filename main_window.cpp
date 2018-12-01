#include "window.h"
#include <gtkmm.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    //vector <string> cust_names;
    //customer_name c;
    //c.get_vector(cust_names);                    
    Gtk::Main app(argc,argv);
    main_menu w;
    //cout<<cust_names[0]<<endl;
    Gtk::Main::run(w);

    return 0;
}