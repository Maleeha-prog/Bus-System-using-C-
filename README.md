# Bus-System-using-C-
In this project you will write a program that implements a variant of a linked list (Bus). A user can install a new bus and can reserve its seat according to its time schedule and route.

Struct Bus
{
int bus_no;
char driver_name[50];
char from[50];
char to[50];
int arrival;
int departure;
int no_of_seats;
Bus *previous;
Bus *next;
};
After that you need to write a class called BusReservation that implements the following functions:
void install_bus(int bus_no, char driver_name[50], char from[50],....., int departure, int no_of_seats.....);
void view bus( int bus_no);
void delete_bus(int bus_no);
void reserve_seat(int bus_no, int seat_no);
