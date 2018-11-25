CXXFLAGS	+=	-std=c++11
GTKFLAGS	=	`/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex:main_window.o window.o
	$(CXX)	$(CXXFLAGS)	-o	final	main_window.o	window.o	$(GTKFLAGS)
main_window.o:main_window.cpp	window.h
	$(CXX)	$(CXXFLAGS)	-c	main_window.cpp	$(GTKFLAGS)
window.o:	window.h	window.cpp 
	$(CXX)	$(CXXFLAGS)	-c	window.cpp	$(GTKFLAGS)