#include <iostream>
#include <vector>
#include <gtkmm.h>
#include "window.h"
#include <string> 

int value=0;
//std::vector <event> event_list;

main_win::main_win()
:box(Gtk::ORIENTATION_VERTICAL),
new_event("New Event"),
edit_event("Edit Event"),
delete_event("Delete Event"),
sort_events("Sort Events")
{

set_size_request(350,200);
set_title("Event Planner");
add(box);

title.set_text("MENU");
box.pack_start(title);

new_event.signal_clicked().connect(sigc::mem_fun(*this,&main_win::New_event));
		box.pack_start(new_event);

edit_event.signal_clicked().connect(sigc::mem_fun(*this,&main_win::Edit_event));
		box.pack_start(edit_event);

delete_event.signal_clicked().connect(sigc::mem_fun(*this,&main_win::Delete_event));
		box.pack_start(delete_event);

sort_events.signal_clicked().connect(sigc::mem_fun(*this,&main_win::Sort_events));
		box.pack_start(sort_events);

show_all_children();
}

main_win:: ~main_win()
{}

void main_win::New_event()
{
	
type_of_event type;
hide();
Gtk::Main::run(type);
hide();
}

void main_win::Delete_event()
{

}

void main_win::Edit_event()
{

}

void main_win::Sort_events()
{

}

type_of_event::type_of_event()
:box(Gtk::ORIENTATION_VERTICAL),
button_wedding("Wedding"),
button_birthday("Birthday"),
button_anniversary("Anniversary"),
button_party("Party"),
button_back("Back")
{

set_size_request(350,200);
set_title("Type of Event");
add(box);

button_wedding.signal_clicked().connect(sigc::mem_fun(*this,&type_of_event::wedding));
		box.pack_start(button_wedding);
        
button_birthday.signal_clicked().connect(sigc::mem_fun(*this,&type_of_event::birthday));
		box.pack_start(button_birthday);
        
button_anniversary.signal_clicked().connect(sigc::mem_fun(*this,&type_of_event::anniversary));
		box.pack_start(button_anniversary);
        
button_party.signal_clicked().connect(sigc::mem_fun(*this,&type_of_event::party));
		box.pack_start(button_party);

button_back.signal_clicked().connect(sigc::mem_fun(*this,&type_of_event::back));
		box.pack_start(button_back);

show_all_children();
}

void type_of_event::wedding()
{
	value = 1;
	hide();
new_eventt n;
Gtk::Main::run(n);
}

void type_of_event::birthday()
{
	value = 2;
	hide();
new_eventt n;
Gtk::Main::run(n);
}

void type_of_event::party()
{
	value = 4;
	hide();
new_eventt n;
Gtk::Main::run(n);
}

void type_of_event::anniversary()
{
	value = 3;
	hide();
new_eventt n;
Gtk::Main::run(n);

}

void type_of_event::back()
{
	hide();
	main_win newwin;
	Gtk::Main::run(newwin);
}

type_of_event::~type_of_event()
{}

new_eventt:: ~new_eventt()
{}

new_eventt::new_eventt()
:box(Gtk::ORIENTATION_VERTICAL),
button_theme("Choose a Theme"),
button_food("Food Package"),
button_date("Date"),
button_numpeople("Number of People"),
button_back("Back")
{

set_size_request(350,200);
set_title("New Event");
add(box);

button_theme.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::pick_new_theme));
		box.pack_start(button_theme);

button_food.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::clicked));
		box.pack_start(button_food);

button_date.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::clicked));
		box.pack_start(button_date);

button_numpeople.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::clicked));
		box.pack_start(button_numpeople);

button_back.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::back));
		box.pack_start(button_back);

show_all_children();



}
void new_eventt::back()
{
	hide();
	type_of_event newwin;
	Gtk::Main::run(newwin);
}

Wedding::Wedding()
{
	set_size_request(450,300);
	set_title("Theme");
    add(box);

	image_1.set("wedding1.jpg");
	box2.pack_start(image_1);
	theme_1.add_label("Modern");
	
	image_2.set("wedding2.jpg");
	box3.pack_start(image_2);
	theme_2.add_label("Rustic");
	
	image_3.set("wedding3.jpg");
	theme_3.add_label("Vintage");
	box4.pack_start(image_3);

	box.pack_start(box2);
	box.pack_start(box3);
	box.pack_start(box4);
	

	theme_1.signal_clicked().connect(sigc::mem_fun(*this,&Wedding::pick_theme1));
	box2.pack_start(theme_1);
	theme_2.signal_clicked().connect(sigc::mem_fun(*this,&Wedding::pick_theme2));
	box3.pack_start(theme_2);
	theme_3.signal_clicked().connect(sigc::mem_fun(*this,&Wedding::pick_theme3));
	box4.pack_start(theme_3);

	show_all_children();



}


void Wedding::pick_theme1()
{
event_theme = "Modern";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
entries.push_back(event_theme);
}

void Wedding::pick_theme2()
{
	
event_theme = "Rustic";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();

}

void Wedding::pick_theme3()
{
event_theme = "Vintage";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
//std::cout<<event_theme<<std::endl;


close();
}



Wedding::~Wedding()
{}

Anniversary::Anniversary()
{
	set_size_request(450,300);
	set_title("Theme");
    add(box);

	image_1.set("anniversary1.jpg");
	box2.pack_start(image_1);
	theme_1.add_label("Cute as Cotton");
	
	image_2.set("anniversary2.jpg");
	box3.pack_start(image_2);
	theme_2.add_label("Lantern Love");
	
	image_3.set("anniversary3.jpg");
	theme_3.add_label("Pretty Plank");
	box4.pack_start(image_3);

	box.pack_start(box2);
	box.pack_start(box3);
	box.pack_start(box4);
	

	theme_1.signal_clicked().connect(sigc::mem_fun(*this,&Anniversary::pick_theme1));
	box2.pack_start(theme_1);
	theme_2.signal_clicked().connect(sigc::mem_fun(*this,&Anniversary::pick_theme2));
	box3.pack_start(theme_2);
	theme_3.signal_clicked().connect(sigc::mem_fun(*this,&Anniversary::pick_theme3));
	box4.pack_start(theme_3);	

	show_all_children();
}

Anniversary::~Anniversary()
{}

void Anniversary::pick_theme1()
{
event_theme = "Cute as Cotton";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}
void Anniversary::pick_theme2()
{
event_theme = "Lantern Love";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}

void Anniversary::pick_theme3()
{
event_theme = "Pretty Plank";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}

Birthday::Birthday()
{
	set_size_request(450,300);
	set_title("Theme");
    add(box);

	image_1.set("birthday1.jpg");
	box2.pack_start(image_1);
	theme_1.add_label("Circus");
	
	image_2.set("birthday2.jpg");
	box3.pack_start(image_2);
	theme_2.add_label("Garden");
	
	image_3.set("birthday3.jpg");
	theme_3.add_label("Marvel");
	box4.pack_start(image_3);

	box.pack_start(box2);
	box.pack_start(box3);
	box.pack_start(box4);
	

	theme_1.signal_clicked().connect(sigc::mem_fun(*this,&Birthday::pick_theme1));
	box2.pack_start(theme_1);
	theme_2.signal_clicked().connect(sigc::mem_fun(*this,&Birthday::pick_theme2));
	box3.pack_start(theme_2);
	theme_3.signal_clicked().connect(sigc::mem_fun(*this,&Birthday::pick_theme3));
	box4.pack_start(theme_3);	

	show_all_children();
}



void Birthday::pick_theme1()
{
event_theme = "Circus";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}
void Birthday::pick_theme2()
{
event_theme = "Garden";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}

void Birthday::pick_theme3()
{
event_theme = "Marvel";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}
Birthday::~Birthday()
{}

Party::Party()
{
	set_size_request(450,300);
	set_title("Theme");
    add(box);

	image_1.set("party1.jpg");
	box2.pack_start(image_1);
	theme_1.add_label("Alice in Wonderland");
	
	image_2.set("party2.jpg");
	box3.pack_start(image_2);
	theme_2.add_label("Black and White");
	
	image_3.set("party3.jpg");
	theme_3.add_label("Masquerade ball");
	box4.pack_start(image_3);

	box.pack_start(box2);
	box.pack_start(box3);
	box.pack_start(box4);
	

	theme_1.signal_clicked().connect(sigc::mem_fun(*this,&Party::pick_theme1));
	box2.pack_start(theme_1);
	theme_2.signal_clicked().connect(sigc::mem_fun(*this,&Party::pick_theme2));
	box3.pack_start(theme_2);
	theme_3.signal_clicked().connect(sigc::mem_fun(*this,&Party::pick_theme3));
	box4.pack_start(theme_3);	

	show_all_children();
}



void Party::pick_theme1()
{
event_theme = "Alice in Wonderland";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}
void Party::pick_theme2()
{
event_theme = "Black and White";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}

void Party::pick_theme3()
{
event_theme = "Masquerade ball";
std::string  di_final = event_theme + " theme picked";
Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
dialog.set_secondary_text(di_final);
dialog.run();
close();
//std::cout<<event_theme<<std::endl;
}
Party::~Party()
{}

void new_eventt::pick_new_theme()
{
	switch(value){
		case 1: new_wedding();
		break;
		case 2: new_birthday();
		break;
		case 3: new_anniversary();
		break;
		case 4: new_party();
		break;
	}
	
}

void new_eventt::new_wedding()
{
Wedding wed;
Gtk::Main::run(wed);
}

void new_eventt::new_birthday()
{
Birthday ber;
Gtk::Main::run(ber);
}

void new_eventt::new_anniversary()
{
Anniversary ann;
Gtk::Main::run(ann);
}

void new_eventt::new_party()
{
Party par;
Gtk::Main::run(par);
}

void new_eventt::clicked()
{
	close();
}




