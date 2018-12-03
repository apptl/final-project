#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm.h>
#include <string> 
#include <iostream>
#include <vector>

using namespace std;

class person_name  //A Class for all the customer names stored in a vector
{
public:
    vector <string> names; 
};

class event  //A Class for a event details - name, theme, cost, food package, and number of people attending
{
public:
    string person_name;
    string registary;
    string event_theme;
    double cost;
    //string food_package;
    int people;
    string date;
    //void set_theme(std::string a);
    //std::string get_theme();
};

class main_menu:public Gtk::Window  //A Class for the user to choose whether he/she is Customer, Guest or Admin
{
public:
    Gtk::Box box;
    Gtk::Button guest,admin,customer;
    Gtk::Label title;

    void Customer();
    void Guest();
    void Admin();
    void Customer_name(); //Creates a object of Class customer_name to create a file of the customer details
    
    main_menu();
    virtual ~main_menu();
};
    
class customer_name:public person_name, public Gtk::Window //A Class to enter the customer name and store it in the vector with the names of all customers
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

class admin_things:public Gtk::Window
{
public:
Gtk::Button sort,edit,back;
Gtk::Box box;
void Sorting();
void Editing();
void Back();    
admin_things();
virtual ~admin_things();
};



class admin_window:public Gtk::Window //A Class for the Admin to edit and sort events
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button send;
    
    admin_window();
    void Admin_win();
    virtual ~admin_window();
    void Send_name();
};



class main_win:public Gtk::Window //A Class for the window that opens up for a Customer to choose options either New event or view event
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

//A Class for the customer to choose the type of event 
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

//A Class for the customer to choose the food package
class food_package: public Gtk::Window
{
public:
    Gtk::Button package_1,package_2,package_3;
    Gtk::VBox box2,box3,box4;
    Gtk::HBox box;
    Gtk::Image image_1,image_2,image_3;
    
    food_package();
    virtual ~food_package();
    void pick_pack1();
    void pick_pack2();
    void pick_pack3();

};


class new_eventt:public event, public Gtk::Window //A Class for the customer to choose the theme, food package, number of poeple, date etc.
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


class edit_eventt:public event,public Gtk::Window //A Class for the Admin to edit the number of people and date of the event
{
    public:
    Gtk::Box box;
    Gtk::Button bydate,bypeople;
    Gtk::Label label;
    
    //void clickedit();
    edit_eventt();
    void e_date();
    void e_people();
    void Edit_event();
    virtual ~edit_eventt();
};

class theme // A Class with three buttons for the three themes in each type of event
{
public:
    //Gtk::Box box;
    Gtk::Button theme_1,theme_2,theme_3;
    Gtk::Box textbox;
    //void theme();
};

class Wedding : public event, public Gtk::Window //A Class for Wedding type of event-pictures for the three different themes
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

class Birthday: public event,public Gtk::Window //A Class for Birthday type of event-pictures for the three different themes
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

class Anniversary : public event,public Gtk::Window //A Class for Anniversary type of event-pictures for the three different themes
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

class Party: public event,public Gtk::Window //A Class for Party type of event-pictures for the three different themes
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

class event_date: public Gtk::Window //A Class for the Customer to enter the date of the event
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

class event_people: public Gtk::Window //A Class for the Customer to enter the number of the people for the event
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

class event_view: public Gtk::Window //A Class for the Customer to view all the event details
{
public:
    Gtk::VBox box;
    Gtk::Dialog MessageDialog;
    Gtk::Button back;
    Gtk::Label label1,label2,label3,label4,label5,label6;
    
    event_view();        
    virtual ~event_view();
    void Back();
};

class change_people:public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button send;
    change_people();
    virtual ~change_people();
    void send_val();
    
    Gtk::Box textbox2;
    Gtk::Label label2;
};

class change_date:public Gtk::Window
{
public:
    Gtk::Box box;
    Gtk::Label label;
    Gtk::Entry input;
    Gtk::Box textbox;
    Gtk::Button send;
    change_date();
    virtual ~change_date();
    void send_val();
};

class sort_package:public Gtk::Window
{

public:
    Gtk::Label label1,label2,label3,label4,label5;
    Gtk::VBox box;
    Gtk::Button click;
    sort_package();
    virtual ~sort_package();

};


#endif