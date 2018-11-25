#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm.h>
#include <string> 
#include <iostream>
#include <vector>


using namespace std;


class event
{
public:

string registary;
string event_theme;
double cost;
string food_package;
int people;
string date;
//void set_theme(std::string a);
//std::string get_theme();

};


class main_win:public Gtk::Window
{
public:
Gtk::Box box;
Gtk::Button new_event,edit_event,sort_events,delete_event;
Gtk::Label title;

void New_event();
void Edit_event();
void Delete_event();
void Sort_events();

main_win();
virtual ~main_win();

};


class type_of_event:public event, public Gtk::Window
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

class Wedding : public event, public Gtk::Window
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

class Birthday: public event, public Gtk::Window
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

class Anniversary : public event,public Gtk::Window
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

class Party: public event, public Gtk::Window
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

#endif