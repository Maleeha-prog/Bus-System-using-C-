#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <unistd.h>
#include<string.h>

using namespace std;

/////////all definations are according to prototypes

struct Bus;                      //this has all data regarding a bus
struct places;                  //this has city map and bus stand names and functions regarding nearby bus stand etc
class BusReservation;          //has functions for instalation,deletion, printing bus data and reserve seat

void available(Bus* count);

void front();
void date();
void display();
void title();
void menu();
void Exit(); 

int main()
{	
  	front();           //simply display the project name
  	system ("PAUSE"); //pause displays a message and waits for the user to hit a key
  	system ("CLS");   //clear the consoule
  	title();          //title page
	menu();
}
struct Bus
{
	int bus_no;
	string driver_name;
	string _from;
	string _to;
	int _arrival_hr;
	int _arrival_min;
	int _departure_hr;
	int _departure_min;
	int no_of_seats;
	int seat_no[30];
	string passanger_name[30];
	Bus *previous=NULL;
	Bus *next=NULL;

Bus() //constructor
{
	for(int i=0;i<30;i++)
	{
    seat_no[i]=0;              //initialize seat_no
	}	
}//constructor defination ends here
};//structure terminated
/////////
struct places
{
    string stations[10][13];
    public:
    	places();
        void available_stations(string check);
        int _stations(string ch);
};
/////////
class BusReservation
{
	Bus* head;
	public:
    BusReservation();
    void install_bus(int bus_no, string, string, string, int, int ,int ,int, int);
    void view_bus( int bus_no);
    void delete_bus(int bus_no);
    void reserve_seat(int bus_no, int seat_no,string);
};
void available(Bus* count)
{
    int i=0;
    if(i<count->no_of_seats)
    {
        cout<<"\t\t\t\tAVAILABLE SEATS ARE:\n";
        while(i!=count->no_of_seats)
        {
            if(count->seat_no[i]==0)
            {
                cout<<"\t\t\t\t"<<i+1<<endl;
            }
            i++;
        }
    }
}

////////////places::functions
places::places(){
    stations[0][0]="I-8_MARKZ";                   //THERE ARE DEFINED BUS STANDS
    stations[1][0]="I-10_MARKZ";
    stations[2][0]="KARACHI_COMPANY";
    stations[3][0]="G-10_MARKZ";
    stations[4][0]="F-11_MARKZ";
    stations[5][0]="G-11_MARKZ";
    stations[6][0]="CENTURUS_MALL";
    stations[7][0]="SHAHEEN_CHOWK";
    stations[8][0]="JINNAH_SUPPER";
    stations[9][0]="SUPER_MARKET";

    stations[0][1]="H-8/1";                //THERE ARE THE PLACES DEFINED FOR THE CITY
    stations[0][2]="I-8/1";                //THE PROGRAM WON'T BE ABLE TO RECOGNIZE ANY PLACE TAYPED USING SPACE BAR
    stations[0][3]="H-8/2";                 //AND ALSO IT IS THESE NAMES ARE CASE SENSITIVE
    stations[0][4]="I-8/2";
    stations[0][5]="H-8/3";
    stations[0][6]="I-8/3";
    stations[0][7]="H-8/4";
    stations[0][8]="I-8/4";
   
    stations[1][1]="I-10/1";
    stations[1][2]="H-9/1";
    stations[1][3]="I-10/2";
    stations[1][4]="H-9/2";
    stations[1][5]="I-10/3";
    stations[1][6]="H-9/3";
    stations[1][7]="I-10/4";
    stations[1][8]="H-9/4";
   
    stations[2][1]="F-9";
    stations[2][2]="G-8/2";
    stations[2][3]="G-8/1";
    stations[2][4]="G-9/3";
    stations[2][5]="G-9/2";
    stations[2][6]="G-9/4";
    stations[2][7]="G-10/4";
    stations[2][8]="G-9/1";
    stations[2][9]="G-10/3";
   
    stations[3][1]="G-10/1";
    stations[3][2]="G-10/2";
    stations[3][3]="G-10/3";
    stations[3][4]="G-10/4";
    stations[3][5]="G-11/3";
    stations[3][6]="G-11/4";
    stations[3][7]="F-10/1";
    stations[3][8]="F-10/4";    
   
    stations[4][1]="F-11/1";
    stations[4][2]="F-11/2";
    stations[4][3]="F-11/3";
    stations[4][4]="F-11/4";
    stations[4][5]="E-11/1";
    stations[4][6]="E-11/2";
    stations[4][7]="E-11/3";
    stations[4][8]="E-11/4";
    stations[4][9]="F-10/1";
    stations[4][10]="F-10/2";
    stations[4][11]="F-10/3";
    stations[4][12]="F-10/4";
   
    stations[5][1]="G-11/1";
    stations[5][2]="G-11/2";
    stations[5][3]="G-11/3";
    stations[5][4]="G-11/4";
    stations[5][5]="F-11/1";
    stations[5][6]="G-10/2";
    stations[5][7]="G-10/1";
    stations[5][8]="F-11/4";
   
    stations[6][1]="F-7/2";
    stations[6][2]="F-7/1";
    stations[6][3]="F-8/1";
    stations[6][4]="F-8/2";
    stations[6][5]="F-8/3";
    stations[6][6]="F-8/4";
    stations[6][7]="F-8/1";
    stations[6][8]="G-8/2";
    stations[6][9]="G-8/3";
   
    stations[7][1]="F-9";
    stations[7][2]="AIR_UNIVERSITY";
    stations[7][3]="BAHRIA_UNIVERSITY";
    stations[7][4]="F-8/2";
    stations[7][5]="F-8/1";
    stations[7][6]="E-9";
   
    stations[8][1]="F-7/1";
    stations[8][2]="F-7/2";
    stations[8][3]="F-7/3";
    stations[8][4]="F-7/4";
    stations[8][5]="F-8/3";
    stations[8][6]="F-8/7";
    stations[8][7]="E-7";
    stations[8][8]="F-6/1";
    stations[8][9]="F-6/2";
   
    stations[9][1]="F-6/1";
    stations[9][2]="F-6/2";
    stations[9][3]="F-6/3";
    stations[9][4]="F-6/4";
    stations[9][5]="F-7/3";
    stations[9][6]="F-7/4";
    stations[9][7]="F-5/1";
    stations[9][8]="F-5/2";	
}
    
void places::available_stations(string check)
{
    cout<<"\n\t\t\t\tBUS STAND IN THE CITY ARE \n\n";
    for(int i=0;i<9;i++)
    {
    	cout<<"\t\t\t\t";
        cout<<stations[i][0]<<" BUS STAND";
        cout<<endl;
    }
    cout<<"\n\n\t\t\t	 **NEAREST BUS STAND**\n\n";
    int i=0;
    while(i!=10)
    {
        for(int j=0;j<12;j++)
        {
            if(check.compare(stations[i][j])==0)
            {
                cout<<"\t\t\t\t"<<stations[i][0]<<" BUS STAND"<<endl;
                j=+12;
            }
        }
        i++;
    }
    cout<<"\n\n";
}

int places::_stations(string ch)
{
	int result=1;
	for(int i=0;i<10;i++)
	{
		result=ch.compare(stations[i][0]);
		if(result==0)
		return result;
	}
	return result;
}

/////////////function defination

BusReservation::BusReservation()
{
	head=NULL;                        //SET head TO NULL
}

void BusReservation :: install_bus(int bus_no, string driver_name, string _from, string _to , int _departure_hr, int _departure_min,int _arrival_hr,int _arrival_min, int no_of_seats)
{
	Bus* temp=new Bus;
	temp->bus_no=bus_no;
	temp->driver_name=driver_name;
	temp->_from=_from;
	temp->_to=_to;
	temp->_departure_hr=_departure_hr;
	temp->_departure_min=_departure_min;
	temp->_arrival_hr=_arrival_hr;
	temp->_arrival_min=_arrival_min;
	temp->no_of_seats=no_of_seats;

if(head==NULL)
{
    head=temp;
    return;
}
else
{
	Bus* count=head;
	while(count->next!=NULL)
	{	
	count=count->next;
	}
	if(count==head)
	{
	head->next=temp;
	temp->previous=head;
	}
	else
	{
	count->next=temp;
	temp->previous=count;
	}
}
}

void BusReservation :: view_bus( int bus_no)
{
	Bus* count= head;
	bool FOUND=false;
	if(count==NULL)
	{
	cout<<"\n\n\n\n\n\n\n";	
	cout<<"\t\t\t\t\t";
	cout<<"BUS NOT AVAILABLE";
	}
	else
	{
	while(count!=NULL)
	{
	if(bus_no==count->bus_no)
	{
	FOUND=true;
	break;
	}
	count=count->next;	
	}
	if(FOUND==true)
	{
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\tBUS NO.       "<<count->bus_no<<endl;	
	cout<<"\t\t\t\tDRIVER NAME   "<<count->driver_name<<endl;
	cout<<"\t\t\t\tFROM          "<<count->_from<<endl;
	cout<<"\t\t\t\tTO            "<<count->_to<<endl;
	cout<<"\t\t\t\tARRIVAL       "<<count->_arrival_hr<<":"<<count->_arrival_min<<endl;
	cout<<"\t\t\t\tDEPARTURE     "<<count->_departure_hr<<":"<<count->_departure_min<<endl;
	cout<<"\t\t\t\tNO. OF SEATS  "<<count->no_of_seats<<endl;
	cout<<"\n\n";
	for(int i=0;i<count->no_of_seats;i++)
	{
    cout<<"\tseat no "<<i+1;
    
	if(count->passanger_name[i]=="\0")
    count->passanger_name[i]="     ";
    cout<<"\tpassanger name "<<count->passanger_name[i];
    cout<<"\t\t";
    if(i%2!=0)
    cout<<endl;
	}
}
else
{
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t";
	cout<<"BUS NOT FOUND";
}
}
}

void BusReservation :: delete_bus( int bus_no)
{
	Bus* count= head;
	bool FOUND=false;
	if(count==NULL)
	{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t";
	cout<<"BUS NOT AVAILABLE";
	}
else
{
	while(count!=NULL)
	{
	if(bus_no==count->bus_no)
	{
	FOUND=true;
	break;
	}
	count=count->next;
	}
if(FOUND==true)
{
	if(count==head)
	{
	head=count->next;
	delete count;
	}
	else
	{
	count->previous->next=count->next;
	if(count->next!=NULL)
	{
	count->next->previous=count->previous;
	}
	count->next=NULL;
	delete count;
	}
}
else
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t";
	cout<<"BUS NOT AVAILABLE";
}
}
}

void BusReservation:: reserve_seat(int bus_no, int seat_no,string _passanger)
{
	Bus* count= head;
    bool FOUND=false;
    int i=2;
    if(count==NULL)
  	{
  	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t";
	cout<<"BUS NOT AVAILABLE";
	}
	else
	{
	while(count!=NULL)
	{
	if(bus_no==count->bus_no)
	{
	FOUND=true;
	break;
	}
	count=count->next;
	}
	
	if(FOUND==true)
	{
	cout<<"\n\n\n\n\t\t\t\tBUS DESTINATION : "<<count->_from<<" to "<<count->_to<<"\n";
	cout<<"\n\n\t\t\t\t\t\t******TIME******    \n\n\t\t\t\tDEPARTURE "<<count->_departure_hr<<":"<<count->_departure_min;
	cout<<"\n\t\t\t\tARRIVAL   "<<count->_arrival_hr<<":"<<count->_arrival_min<<endl;	  
	cout<<   count->seat_no[seat_no-1]<<endl;
	cout<<seat_no<<endl;
	if(count->seat_no[seat_no-1]==seat_no||seat_no>count->no_of_seats)
    {
    cout<<"\t\t\t\t\t*****SORRY******\n\t\t\tTHIS SEAT IS ALREADY RESERVED OR DO NOT EXIST\n\n";
    available(count);
    do
    {
    cout<<"\n\n\t\t\t\t1.BOOK ANOTHER SEAT";
    cout<<"\n\n\t\t\t\t2.BOOK ANOTHER BUS";
    cin>>i;
    switch(i)
    {
       case 1:
       cout<<"\n\t\t\t\tENTER SEAT NO ";
       cin>>seat_no;
       if(count->seat_no[seat_no-1]==seat_no||seat_no>count->no_of_seats)
       i=2;
       else
       	count->seat_no[seat_no-1]=seat_no;
	    count->passanger_name[seat_no-1]=_passanger;
       break;
      
       case 2:
       return;
       
       default:
       cout<<"\n\t\t\tinvalid input";
       break;
   }
   }while(i!=1);
   }
       	count->seat_no[seat_no-1]=seat_no;
	    count->passanger_name[seat_no-1]=_passanger;
	return;	
}
	else
	{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t";
	cout<<"BUS NOT AVAILABLE";
	}
	}
}

void loading()
{
	int process=0;	
	for(process=0;process<25;process++)
    {
    usleep(50000);
    cout<<".";
    }
}
void date(){
  	   // current date/time based on current system
  time_t now = time(0);
   
   // convert now to string form
  char* dt = ctime(&now);
  cout<<"\n\n\n";
  cout<<"\t\t\t\t\t"<<dt;
  
  }
  
void display(void){
  cout<<"\n\n\n\n";
  cout<<"\t\t\t\t\t       -------------------------\n";
  cout<<"\t\t\t\t\t        |ISLAMABAD BUS SERVICE|  \n";
  cout<<"\t\t\t\t\t       -------------------------\n";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  }
  
void front(void){
  cout<<"\n\n\n";
  cout<<"\n\n\n\n\n\n";
  cout<<"\n";
  cout<<"\t\t\t\t\t       -------------------------\n";
  cout<<"\t\t\t\t\t        |ISLAMABAD BUS SERVICE|  \n";
  cout<<"\t\t\t\t\t       -------------------------\n";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  }  

void title()
 {  
  system("cls");
  date();
  cout<<"\n\t\t\t\t       -------------------------\n";
  cout<<"\t\t\t\t        |ISLAMABAD BUS SERVICE|\n";
  cout<<"\t\t\t\t       -------------------------\n";
  cout<<"\n\n\n";
  cout<<"\t\t\t\t";
  cout<<"Prepared By    ";
  cout<<":";
  cout<<"   TAYYABA and MALEEHA";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<"Mini Project    ";
  cout<<":";
  cout<<"  Bus Reservation System";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<"Guided By      ";
  cout<<":";
  cout<<"   ENGINEER MUHAMMAD SAD";
  cout<<"\n\n";
  cout<<"\t\t\t\t    Press Enter to continue......";
  cout<<"\n\n";
  getchar();
  cout<<"\t\t\t\tLoading";
  loading();
}

void menu()
{
  	char input='\0';
	BusReservation bus;
	places p;
	int bus_no;
	string driver_name;
	string from;
	string to;
	char colon;
	int departure_hr;
	int departure_min;
	int arrival_hr;
	int arrival_min;
	int no_of_seats;
	string user;
	string loc;
	int seat_no;
  do
  {
  system("cls");
  display();
  cout<<" 1. ADMIN\n\n";
  cout<<"\t\t\t\t";
  cout<<" 2. USER\n\n";
  cout<<"\t\t\t\t"; 
  cout<<" 3. Exit\n\n";
  cout<<"\t\t\t\t";
  cout<<"Choose options:[1/2/3]:";
  fflush(stdin);
  cin>>input;
  system("cls");
  switch(input)
  {
  	case '1':
  	cin.ignore();
  	do
  {
  system("cls");
  display();
  cout<<" 1. INSTALL BUS\n\n";
  cout<<"\t\t\t\t";
  cout<<" 2. VIEW BUS\n\n";
  cout<<"\t\t\t\t"; 
  cout<<" 3. DELETE BUS\n\n";
  cout<<"\t\t\t\t";
  cout<<" 4. SIGN OUT\n\n";
  cout<<"\t\t\t\t";
  cout<<"Choose options:[1/2/3/4]:";
  fflush(stdin);
  cin>>input;
  system("cls");
  switch(input)
  {
  	case '1':
  		cin.ignore();
  		cout<<"\n\n\n\n\n\n\n\n\n";
  		cout<<"\n\n\t\t\t\tBUS NO              : ";
  		cin>>bus_no;
  		cout<<"\t\t\t\tDRIVER NAME         : ";
  		cin>>driver_name;
  		cout<<"\t\t\t\tFROM                : ";
  		cin>>from;
  		while(p._stations(from)!=0)
  		{cout<<"\n\n\t\t\t\t\tNO SUCH STATION EXIST IN YOUR CITY\n\n";
  		 cout<<"		\tENTER CORRECT LOCATION : ";
		 cin>>from;
		 cout<<"\n\n"; }
  		 cout<<"\t\t\t\tTO                  : ";
  		cin>>to;
  		while(p._stations(to)!=0)
  		{cout<<"\n\n\t\t\t\t\tNO SUCH STATION EXIST IN YOUR CITY\n\n";
  		 cout<<"\t\t\t\tENTER CORRECT LOCATION     : ";
		 cin>>to;
		 cout<<"\n\n"; }  		
  		cout<<"\t\t\t\tDEPARTURE TIME      : ";
  		cin>>departure_hr>>colon>>departure_min;
  		cout<<"\t\t\t\tARRIVAL TIME        : ";
  		cin>>arrival_hr>>colon>>arrival_min;
  		cout<<"\t\t\t\tNO OF SEATS         : ";
  		cin>>no_of_seats;
  		while(no_of_seats>30)
  		{ cout<<"\n\n\t\t\t\tNO BUS CAN HAVE MORE THAN 30 SEATS  \n ";
  		cout<<"\t\t\tNO OF SEATS         : ";
  		cin>>no_of_seats;
		  }
  		bus.install_bus(bus_no,driver_name,from,to,departure_hr,departure_min,arrival_hr,arrival_min,no_of_seats);
  		cout<<"\n\n\n\n";
  		system("pause");
  	break;
	 
	case '2':
		cin.ignore();
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t\tENTER BUS NO. : ";
		cin>>bus_no;
		system("cls");
	    bus.view_bus(bus_no);
	    cout<<"\n\n\t";
	    system("pause");
	break;
	
	case '3':
		cin.ignore();
		cout<<"\n\n\n\n\n\t\t\tENTER BUS NO. : ";
		cin>>bus_no;
		bus.delete_bus(bus_no);
	break;
	
	case '4':
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    getchar();
    cout<<"\t\t\t\tSigning out";
    loading();
	break;	
	
	default:
		cout<<"\n\n\n\n\n";
	    cout<<"\t\t\t\tinvalid input\n\n";
		system("pause");
	break;		  	
  }
}while(input!='4');
  	break;
	 
	case '2':
		cin.ignore();
		cout<<"\n\n\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\tUSER NAME              : ";
	    cin>>user;
	    cout<<"\t\t\t\tENTER PICK-UP LOCATION : ";
	    cin>>loc;
	    p.available_stations(loc);
	    cout<<"\t\t\t\tENTER BUS NO           : ";
	    cin.ignore();
	    cin>>bus_no;
	    cout<<"\t\t\t\tSEAT NO                : ";
	    cin>>seat_no;
	    bus.reserve_seat(bus_no, seat_no ,user);
	    cout<<"\n\n\n";
	    system("pause");
	break;
	
	case '3':
		cin.ignore();
		Exit();
	break;
		
	default:
		cout<<"\n\n\n\n\n";
	    cout<<"\t\t\t\tinvalid input\n\n";
		system("pause");	  	
  }
}while(input!='\0');
}

void Exit()                                 //this function exit end execution whenever called
      {
       system("cls");
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
       cout<<"\t\t\t\t\t";
       cout<<"BROUGHT TO YOU BY DEPARTMENT OF MTS";
       cout<<"\n\n";
       cout<<"\t\t\t\t";
       cout<<"   Press Enter to Continue Exit Program...";
       cout<<"\n\n\n\n\n\n\n\n\n\n\n\n"; 
       getchar();
       exit(0);
      }
  
    

