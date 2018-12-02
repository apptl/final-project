#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm.h>
#include <string> 
#include <iostream>
#include <vector>

using namespace std;

class person_name
{
public:
vector <string> names; 
};

class event
{
public:
    string person_name;
    string registary;
    string event_theme;
    double cost;
    string food_package;
    int people;
    string date;
    //void set_theme(std::string a);
    //std::string get_theme();
};

class main_menu:public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Button guest,admin,customer;
    Gtk::Label title;

    void Customer();
    void Guest();
    void Admin();
    void Customer_name();
    


    main_menu();
    virtual ~main_menu();
};
    
class customer_name:public person_name, public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button send;
    //std::vector<std::string> cust_names;
    customer_name();
    virtual ~customer_name();
    
    void send_val();
};

class admin_window:public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button edit;
    
    admin_window();
    virtual ~admin_window();
    void Edit_event();
};

class main_win:public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Button new_event,view_event,back;
    Gtk::Label title;

    void New_event();
    void View_event();
    
    void Back();

    main_win();
    virtual ~main_win();
};

class type_of_event:public event,public person_name, public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Button button_wedding,button_birthday,button_anniversary,button_party,button_back;
    Gtk::Label label;
    void clicked();
    type_of_event();
    virtual ~type_of_event();

    void wedding();
    void birthday();
    void anniversary();
    void party();
    void back();
    int get_value();
};

class new_eventt:public event, public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Button button_theme,button_food,button_date,button_numpeople,button_back;
    Gtk::Label label;
    void clicked();
    void pick_new_theme();
    void pick_food_package();
    void pick_the_date();
    void pick_num_people();
    new_eventt();
    void new_wedding();
    void new_birthday();
    void new_anniversary();
    void new_party();
    void back();

    virtual ~new_eventt();
};

class edit_eventt:public event,public Gtk::Window
{
    public:
    Gtk::Box box;
    Gtk::Button button;
    Gtk::Label label;
    //void clickedit();
    edit_eventt();
    virtual ~edit_eventt();
};

class theme
{
public:
    //Gtk::Box box;
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;
    //void theme();
};

class eventlist
{
public:
    std::vector <event> entries;
};

class Wedding : public event,public eventlist, public Gtk::Window
{
public:
    Wedding();
    virtual ~Wedding();
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;
    Gtk::VBox box2,box3,box4;
    Gtk::HBox box;
    Gtk::Image image_1,image_2,image_3;
    void pick_theme1();
    void pick_theme2();
    void pick_theme3();
};

class Birthday: public event,public eventlist,public Gtk::Window
{
public:
    Birthday();
    virtual ~Birthday();   
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;     
    Gtk::VBox box2,box3,box4;
    Gtk::HBox box;
    Gtk::Image image_1,image_2,image_3;
    void pick_theme1();
    void pick_theme2();
    void pick_theme3();
};

class Anniversary : public event,public eventlist,public Gtk::Window
{
public:
    Anniversary();
    virtual ~Anniversary();
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;
    Gtk::VBox box2,box3,box4;
    Gtk::HBox box;
    Gtk::Image image_1,image_2,image_3;
    void pick_theme1();
    void pick_theme2();
    void pick_theme3();
};

class Party: public event,public eventlist,public Gtk::Window
{
public:
    Party();
    virtual ~Party();
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;
    Gtk::VBox box2,box3,box4;
    Gtk::HBox box;
    Gtk::Image image_1,image_2,image_3;
    void pick_theme1();
    void pick_theme2();
    void pick_theme3();
};

class event_date: public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button pick,back;
    
    event_date();
    virtual ~event_date();
    void Pick_date();
    void Back();
};

class event_people: public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button enter,back;
    
    event_people();
    virtual ~event_people();
    void Enter();
    void Back();
};

class event_view: public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Dialog MessageDialog;
    Gtk::Label label;
    
    event_view();        
    virtual ~event_view();
};

#endif