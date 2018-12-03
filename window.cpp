#include <iostream>
#include <vector>
#include <gtkmm.h>
#include "window.h"
#include <string> 
#include <fstream>

// A Window created to choose whether the user is - Customer, Admin, or Guest
main_menu::main_menu() 
:box(Gtk::ORIENTATION_VERTICAL),
customer("Customer"),
guest("Guest"),
admin("Admin")
{
	set_size_request(350,200);
	set_title("MAIN MENU");
	add(box);

	customer.signal_clicked().connect(sigc::mem_fun(*this,&main_menu::Customer));
		box.pack_start(customer);

	guest.signal_clicked().connect(sigc::mem_fun(*this,&main_menu::Guest));
			box.pack_start(guest);

	admin.signal_clicked().connect(sigc::mem_fun(*this,&main_menu::Admin));
			box.pack_start(admin);

	show_all_children();
}

main_menu::~main_menu() //Destructor for main_menu
{}

void main_menu::Admin()
{
	admin_things new_things;
	hide();
	Gtk::Main::run(new_things);
}

customer_name::customer_name() // A Window for the customer to enter their name
:box(Gtk::ORIENTATION_VERTICAL),
send("Send")
{
	set_size_request(350,200);
	set_title("Name");
	add(box);

    label.set_text("Enter the customer name: ");
    box.pack_start(label);
    box.pack_start(input);
    box.pack_start(textbox);
	
	send.signal_clicked().connect(sigc::mem_fun(*this,&customer_name::send_val));
		box.pack_start(send);

	show_all_children();
}
    

void customer_name::send_val() // A function to open a file on the Customer's name to enter their event details
{
    std::string	customerName = input.get_text();
	main_win newwin;
	hide();
    std::fstream fp;
	std::string customer_file = customerName + ".txt";
	fp.open("file.txt",ios::app);	
	fp<<customer_file<<endl;
	fp.close();
	Gtk::Main::run(newwin);
}

customer_name::~customer_name() // Destructor for customer_name
{}

admin_things::admin_things()
:box(Gtk::ORIENTATION_VERTICAL),
sort("Sort"),
edit("Edit"),
back("Back")
{
	set_size_request(350,200);
	set_title("Admin");
	add(box);

	sort.signal_clicked().connect(sigc::mem_fun(*this,&admin_things::Sorting));
	box.pack_start(sort);

    edit.signal_clicked().connect(sigc::mem_fun(*this,&admin_things::Editing));
	box.pack_start(edit);

	back.signal_clicked().connect(sigc::mem_fun(*this,&admin_things::Back));
	box.pack_start(back);
	

    show_all_children();
	}
admin_things::~admin_things()
	{

	}


void admin_things::Sorting()
{
		
}
void admin_things::Editing()
{
edit_eventt new_win_admin;
hide();
Gtk::Main::run(new_win_admin);
}

void admin_things::Back()
{

}

admin_window::admin_window() // A Window for the admin to edit or sort the event based on the customer's name
:box(Gtk::ORIENTATION_VERTICAL),
send("Send")
{
	set_size_request(350,200);
	set_title("info");
	add(box);
	
    label.set_text("Enter the customer's name: ");
    box.pack_start(label);
    box.pack_start(input);
    box.pack_start(textbox);

	send.signal_clicked().connect(sigc::mem_fun(*this,&admin_window::Send_name));
		box.pack_start(send);

    show_all_children();
}
int value=0;

void admin_window::Send_name() // A function to get the name entered by the admin 
{
	std::string e_name = input.get_text();
	e_name = e_name + ".txt";
	std::fstream ofile;
	ofile.open("edit.txt",ios::out | ios::app);
	ofile<<e_name;
	ofile.close();

	change_people people_new;
   hide();
    Gtk::Main::run(people_new);
}


admin_window::~admin_window()
{}



void main_menu:: Customer() // A function to create an object of the customer_name class
{
    customer_name new_name;
	hide();
	Gtk::Main::run(new_name);
}
	
void main_menu:: Guest()
{
			
}

int number_of_people = 0;

main_win::main_win() // A Window for the Customer to choose whether to create a new event of view event details
:box(Gtk::ORIENTATION_VERTICAL),
new_event("New Event"),
view_event("View event"),
back("Back")
{
	set_size_request(350,200);
	set_title("Event Planner");
	add(box);

	title.set_text("MENU");
	box.pack_start(title);

	new_event.signal_clicked().connect(sigc::mem_fun(*this,&main_win::New_event));
		box.pack_start(new_event);

	view_event.signal_clicked().connect(sigc::mem_fun(*this,&main_win::View_event));
		box.pack_start(view_event);

	back.signal_clicked().connect(sigc::mem_fun(*this,&main_win::Back));
		box.pack_start(back);

	show_all_children();
}

main_win:: ~main_win()
{}

event_view::event_view() // A Window for the customer to view their event details
{
	set_size_request(350,200);
	set_title("View Your Event Details");
	add(box);
	
    std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	file_names.close();

	int size = vector_filesnames.size();
	
	std::string file_use = vector_filesnames[size -1];
	
	std::vector <std::string> vector_data;
	std::string data_string;
        
	std::ifstream ifile;
	ifile.open(file_use, ios::in | ios::app);
	while(!ifile.eof()){
		std::getline(ifile,data_string);
    	vector_data.push_back(data_string);
	}
   
	ifile.close();

	label1.set_text(vector_data[0]);
		box.pack_start(label1);

	label2.set_text(vector_data[1]);
		box.pack_start(label2);

	label3.set_text(vector_data[2]);
		box.pack_start(label3);

	label4.set_text(vector_data[3]);
		box.pack_start(label4);

	label5.set_text(vector_data[4]);
		box.pack_start(label5);

	label6.set_text(vector_data[5]);
		box.pack_start(label6);

	back.signal_clicked().connect(sigc::mem_fun(*this,&event_view::Back));
		box.pack_start(back);

	show_all_children();
}

event_view::~event_view()
{}

void event_view:: Back() //A function for the object of main_menu class
{
	main_menu newwin;
	hide();
	Gtk::Main::run(newwin);
	hide();
}

void main_win:: View_event() // A function for the object of event_view class
{
	event_view new_view;
	hide();
	Gtk::Main::run(new_view);
}

void main_win:: Back() // A function for the object of main_menu class
{
	main_menu newwin;
	hide();
	Gtk::Main::run(newwin);
	hide();
}

void main_win:: New_event() // A function for the object of type_of_event class
{			
	type_of_event type;
	hide();
	Gtk::Main::run(type);
	hide();
}

type_of_event::type_of_event() // A Window for the Customer to choose the type of event 
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

void type_of_event::wedding() // A Function to enter the details of wedding that the Customer has chosen 
{
	value = 1;
	hide();
	new_eventt n;
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	

	file_names.close();

	int size = vector_filesnames.size();
	
	std::string file_use = vector_filesnames[size -1];
	
        
	std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Event: Wedding"<<std::endl;
	ofile.close();
	Gtk::Main::run(n);
	close();
}

void type_of_event::birthday() //A Function to enter the details of birthday that the Customer has chosen
{
	value = 2;
	hide();
	new_eventt n;
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	

	file_names.close();

	int size = vector_filesnames.size();
    
	std::string file_use = vector_filesnames[size -1];
    
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Event: Birthday"<<std::endl;
	ofile.close();
		
	Gtk::Main::run(n);
}

void type_of_event::party() //A Function to enter the details of party that the Customer has chosen
{
	value = 4;
	hide();
	new_eventt n;
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	

	file_names.close();

	int size = vector_filesnames.size();
    
	std::string file_use = vector_filesnames[size -1];
    
        
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Event: Party"<<std::endl;
	ofile.close();
	Gtk::Main::run(n);		
}

void type_of_event::anniversary() //A Function to enter the details of anniversary that the Customer has chosen
{
	value = 3;
	hide();
	new_eventt n;
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();

	int size = vector_filesnames.size();
    
	std::string file_use = vector_filesnames[size -1];
    
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Event: Anniversary"<<std::endl;
	ofile.close();
	Gtk::Main::run(n);
}

void type_of_event::back()
{
	hide();
	main_win newwin;
	Gtk::Main::run(newwin);
}

type_of_event:: ~type_of_event()
{}

food_package::food_package()
{ 
set_size_request(450,300);
	set_title("Food Package");
	add(box);

	image_1.set("package1.jpg");
		box2.pack_start(image_1);
		package_1.add_label("Package 1");
			
	image_2.set("package2.jpg");
		box3.pack_start(image_2);
		package_2.add_label("Package 2");
			
	image_3.set("package3.jpg");
		package_3.add_label("Package 3");
		box4.pack_start(image_3);

	box.pack_start(box2);
	box.pack_start(box3);
	box.pack_start(box4);
			

	package_1.signal_clicked().connect(sigc::mem_fun(*this,&food_package::pick_pack1));
		box2.pack_start(package_1);
	package_2.signal_clicked().connect(sigc::mem_fun(*this,&food_package::pick_pack2));
		box3.pack_start(package_2);
	package_3.signal_clicked().connect(sigc::mem_fun(*this,&food_package::pick_pack3));
		box4.pack_start(package_3);	

	show_all_children();

}

food_package::~food_package()
{}
event_people::event_people() // A Window for the Customer to enter the # people attending
:box(Gtk::ORIENTATION_VERTICAL),
enter("Enter"),
back("Back")
{
    set_size_request(350,200);
	set_title("Number of people");
	add(box);

	label.set_text("Enter the amount of people: ");
    box.pack_start(label);
    box.pack_start(input);
    box.pack_start(textbox);

	enter.signal_clicked().connect(sigc::mem_fun(*this,&event_people::Enter));
		box.pack_start(enter);

	back.signal_clicked().connect(sigc::mem_fun(*this,&event_people::Back));
		box.pack_start(back);

	show_all_children();
}

event_people::~event_people()
{}

void event_people::Back()
{
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}

void event_people::Enter() // A function to write to the file the # of people that the Customer has entered 
{
	std::string	Num_of_people = input.get_text();
	number_of_people = stoi(Num_of_people);
	
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
		vector_filesnames.push_back(name);
	}

	file_names.close();

	int size = vector_filesnames.size();
        
	std::string file_use = vector_filesnames[size -1];     	     
	std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"People: "<<Num_of_people<<std::endl;
	ofile.close();
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}

void food_package::pick_pack1()
{ 
	std::string package_name = "package 1";
	std::string  di_final = package_name + "  picked";
	Gtk::MessageDialog dialog(*this,"Food Package",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	std::string name;
	
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Food Package: foodpackage1"<<std::endl;
	float t_cost = number_of_people * 17.99;
	ofile<<"Cost: $"<<t_cost<<std::endl;
	ofile.close();
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);


}

void food_package::pick_pack2()
{ 
	std::string package_name = "package 2";
	std::string  di_final = package_name + "  picked";
	Gtk::MessageDialog dialog(*this,"Food Package",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	std::string name;
	
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Food Package: foodpackage2"<<std::endl;
	float t_cost = number_of_people * 20.99;
	ofile<<"Cost: $"<<t_cost<<std::endl;
	ofile.close();
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}

void food_package::pick_pack3()
{ 
	std::string package_name = "package 3";
	std::string  di_final = package_name + "  picked";
	Gtk::MessageDialog dialog(*this,"Food Package",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	std::string name;
	
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Food Package: foodpackage3"<<std::endl;
	float t_cost = number_of_people * 25.99;
	ofile<<"Cost: $"<<t_cost<<std::endl;
	ofile.close();

	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}


new_eventt:: ~new_eventt()
{}

new_eventt::new_eventt() // A Window for the Customer to choose the details of the event 
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

	button_numpeople.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::pick_num_people));
		box.pack_start(button_numpeople);

	button_food.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::pick_food_package));
		box.pack_start(button_food);

	button_date.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::pick_the_date));
		box.pack_start(button_date);

	

	button_back.signal_clicked().connect(sigc::mem_fun(*this,&new_eventt::back));
		box.pack_start(button_back);

	show_all_children();
}



event_date::event_date() // A Window for the Customer to enter the date of the event
:box(Gtk::ORIENTATION_VERTICAL),
pick("Pick"),
back("Back")
{
    set_size_request(350,200);
	set_title("Pick a Date");
	add(box);

	label.set_text("Enter the Date(MM/DD/YYYY): ");
    box.pack_start(label);
    box.pack_start(input);
    box.pack_start(textbox);

	pick.signal_clicked().connect(sigc::mem_fun(*this,&event_date::Pick_date));
		box.pack_start(pick);

	back.signal_clicked().connect(sigc::mem_fun(*this,&event_date::Back));
		box.pack_start(back);

	show_all_children();
}

event_date::~event_date()
{}

void event_date::Back()
{
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}

void event_date::Pick_date() // A function enter the date the Customer has choosen 
{
	std::string	Date = input.get_text();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();

	int size = vector_filesnames.size();
        
	std::string file_use = vector_filesnames[size -1];
     	   
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Date: "<<Date<<std::endl;
	ofile.close();
	new_eventt event_back;
	hide();
	Gtk::Main::run(event_back);
}



void new_eventt::pick_the_date() // A function for an object of class event_date
{
	event_date new_date;
	hide();
	Gtk::Main::run(new_date);
}

void new_eventt::pick_num_people() // A function for an object of class event_people
{
	event_people amount_ppl;
	hide();
	Gtk::Main::run(amount_ppl);
}

void new_eventt::pick_food_package() 
	{
	food_package pack;
	hide();
	Gtk::Main::run(pack);
	}


void new_eventt::back()
{
	type_of_event newwin;
	hide();
	Gtk::Main::run(newwin);
}

Wedding::Wedding() // A Window that allows the user to choose their theme for Wedding
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

void Wedding::pick_theme1() // A function to write the option the Customer picked
{
	event_theme = "Modern";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();

	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Modern"<<std::endl;
	ofile.close();
}

void Wedding::pick_theme2() // A function to write the option the Customer picked
{
	event_theme = "Rustic";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Rustic"<<std::endl;
	ofile.close();
}

void Wedding::pick_theme3() // A function to write the option the Customer picked
{
	event_theme = "Vintage";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Vintage"<<std::endl;
	ofile.close();
	close();
}

Wedding::~Wedding()
{}

Anniversary::Anniversary() // A Window that allows the user to choose their theme for Anniversary
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

void Anniversary::pick_theme1() // A function to write the option the Customer picked
{
	event_theme = "Cute as Cotton";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}
		
	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Cute as Cotton"<<std::endl;
	ofile.close();
	close();
	
}

void Anniversary::pick_theme2() // A function to write the option the Customer picked
{ 
	event_theme = "Lantern Love";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Lantern Love"<<std::endl;
	ofile.close();
}

void Anniversary::pick_theme3() // A function to write the option the Customer picked
{
	event_theme = "Pretty Plank";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Pretty Plank"<<std::endl;
	ofile.close();
}

Birthday::Birthday() //A Window that allows the user to choose their theme for Anniversary
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

void Birthday::pick_theme1() // A function to write the option the Customer picked
{
	event_theme = "Circus";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Circus"<<std::endl;
	ofile.close();
}

void Birthday::pick_theme2() // A function to write the option the Customer picked
{
	event_theme = "Garden";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
	std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Garden"<<std::endl;
	ofile.close();
}

void Birthday::pick_theme3() // A function to write the option the Customer picked
{
	event_theme = "Marvel";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
	std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Marvel"<<std::endl;
	ofile.close();
}

Birthday::~Birthday()
{}

Party::Party() //A Window that allows the user to choose their theme for Anniversary
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
		theme_3.add_label("Masquerade Ball");
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

void Party::pick_theme1() // A function to write the option the Customer picked
{
	event_theme = "Alice in Wonderland";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
    	vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Alice in Wonderland"<<std::endl;
	ofile.close();
}

void Party::pick_theme2() // A function to write the option the Customer picked
{
	event_theme = "Black and White";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Black and White"<<std::endl;
	ofile.close();
}

void Party::pick_theme3() // A function to write the option the Customer picked
{
	event_theme = "Masquerade Ball";
	std::string  di_final = event_theme + " theme picked";
	Gtk::MessageDialog dialog(*this,"Theme",false,Gtk::MESSAGE_INFO);	
	dialog.set_secondary_text(di_final);
	dialog.run();
	close();
	
	std::string name;
	std:string temp;
	std::ifstream file_names;
	std::vector <std::string> vector_filesnames;

	file_names.open("file.txt");
	while(!file_names.eof()){
		file_names>>name;
        vector_filesnames.push_back(name);
	}

	file_names.close();
	int size = vector_filesnames.size();  
	std::string file_use = vector_filesnames[size -1];    	
    std::fstream ofile;
	ofile.open(file_use, ios::in | ios::app);
	ofile<<"Theme: Masquerade Ball"<<std::endl;
	ofile.close();
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

edit_eventt::edit_eventt()
:box(Gtk::ORIENTATION_VERTICAL),
bydate("Edit Date"),
bypeople("Edit people")
{
set_size_request(350,200);
	set_title("Edit event");
	add(box);
	
	bydate.signal_clicked().connect(sigc::mem_fun(*this,&edit_eventt::e_date));
		box.pack_start(bydate);
	bypeople.signal_clicked().connect(sigc::mem_fun(*this,&edit_eventt::e_people));
		box.pack_start(bypeople);

    show_all_children();

}

void edit_eventt::e_date()
{
    
}



void edit_eventt::e_people() //A function to edit the number of people for a customer
{
	
admin_window open_win;
hide();
Gtk::Main::run(open_win);
}

edit_eventt::~edit_eventt()
{}

change_people::change_people()
:box(Gtk::ORIENTATION_VERTICAL),
send("Send")
{
	set_size_request(350,200);
	set_title("Edit");
	add(box);

	

    label.set_text("Enter the new # people: ");
    box.pack_start(label);
    box.pack_start(input);
    box.pack_start(textbox);

	


	
	send.signal_clicked().connect(sigc::mem_fun(*this,&change_people::send_val));
		box.pack_start(send);

	show_all_children();
}
change_people::~change_people()
{} 

void change_people::send_val() // A function to open a file on the Customer's name to enter their event details
{
    std::string	new_num_people = input.get_text(); 
	
	std::string file_name;
	std::string temp;
	std::fstream ifile;
	ifile.open("edit.txt");
	ifile>>file_name;
	ifile.close();
	std::vector<std::string> data;
	
	std::fstream ofile;
	ofile.open(file_name,ios::out | ios::app);

	while(!ofile.eof()){
    getline(ofile,temp);
	data.push_back(temp);
	}
	data[2] = "People: " + new_num_people;
	ofile.close();	

	std::fstream tfile;
	tfile.open(file_name, ios::trunc);
	for(int i=0; i<data.size();i++){
		tfile<<data[i]<<std::endl;
	}

tfile.close();
}	



	



