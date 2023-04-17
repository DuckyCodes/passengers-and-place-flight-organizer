// q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Passengers
{
protected:
    /*
    member variables
     passenger’s name
       fare
        points.*/
    string name;
    double fare;
    int points;

    double total;
public:
    /*Passenger class must have 3 accessors, 3 mutators, a constructor with three parameters, an
input function to read the passenger’s info, and an output function to display the passenger’s
info.*/
    //3 accessors
    string gName()const;
    double gFare() const;
    int gPoints()const;
    double gTotal() const;
    //3 mutators
     void sName(const string);
     void sFare(const double);
     void sPoints(const int);


     void sTotal(const double);

     //input function to read the passenger’s info
     void input();

     //output function to display the passenger’s info.
     void output()const;

     Passengers();
     //constructor with three parameters
     Passengers(const string&, const double&, const int&);

   
};
string Passengers::gName()const
{
    return this->name;
}
double Passengers :: gFare() const
{
    return this->fare;
}
int Passengers :: gPoints()const
{
    return this->points;
}
double Passengers::gTotal() const
{
    return this->total;
}
void Passengers::sTotal(const double x)
{
    this->total = x;
}
//3 mutators
void Passengers ::sName(const string x)
{
    this->name = x;
}
void Passengers::sFare(const double x)
{
    this->fare = x;
}
void Passengers::sPoints(const int x)
{
    this->points = x;
}

//input function to read the passenger’s info
void Passengers::input()
{
    cout << "enter name of the passenger:" << endl;
    cin>>name;

    cout << "enter the passengers fare price:\n";
    cin >> fare;

    cout << "enter the passengers points: \n";
    cin >> points;

}

//output function to display the passenger’s info.
void Passengers::output()const
{
    cout << "name: " << name<<endl;
    cout << "fare price: $" << fare<<endl;
    cout << "points: " << points<<endl;
}

//constructor with three parameters
Passengers::Passengers()
{
    name = "Joh";
    fare = 300;
    points = 300;
    this->total = fare / 2 + points / 2;
}
Passengers::Passengers(const string& a , const double& b, const int& c)
{
    name = a;
    fare = b;
    points = c;
    this->total = fare/2 + points/2;
}


//class called Flight,
class Flight 
{
protected:
    //store a string for the flight number
    string Number;

    int capacity;
    int numofpassengers;
    //a dynamic array of Passenger objects
      Passengers *array;
public:
    string gNumber()const;
    int gCapacity();
    int gnumofpassengers() const;

    void sNumber(const string);
    void sCapacity(int);
    void snumofpassengers(const int);

    Flight();
    Flight(const string&);

    ~Flight();

    //function called insert (for adding a passenger)
    void insert(Passengers&);

    //display (to display the name fare, and points of all passengers in ascending order)
    void display();
    
    //leave (for choosing the passenger who leaves the aircraft and removing his/her info from the passenger list)
    void leave();
};
string Flight::gNumber()const
{
    return this->Number;
}
int Flight:: gCapacity() 
{
    return this->capacity;
}
int Flight:: gnumofpassengers() const

{
    return this->numofpassengers;
}

void Flight::sNumber(const string x)
{
    this->Number = x;
}
void Flight::sCapacity(int x)
{
    this->capacity = x;
}
void Flight::snumofpassengers(const int x)
{
    this->numofpassengers = x;
}

Flight::Flight()
{
    Number = " ";
    capacity = 5;
    
    array = new Passengers[numofpassengers];
    numofpassengers = 0;

}
Flight::Flight(const string& a)
    {
    Number = a;
    capacity = 5;
    
    array = new Passengers[numofpassengers];
    numofpassengers = 0;
    }

Flight::~Flight()
{
    delete[] array;
}
//function called insert (for adding a passenger)
void Flight:: insert(Passengers& x)
{
    array[numofpassengers] = x;
    numofpassengers++;
    
}

//display (to display the name fare, and points of all passengers in ascending order)
void Flight::display()
{
    for (int i = 0; i < numofpassengers; i++) {
        for (int j = i; j < numofpassengers; j++) {
            if (array[i].gTotal() > array[j + 1].gTotal())
            {
                swap(array[i], array[j + 1]);
            }

        }
    }
    for (int i = 0; i < numofpassengers;i++)
    {
        array[i].output();
        
    }
}

//leave (for choosing the passenger who leaves the aircraft and removing his/her info from the passenger list)
void Flight::leave()
{

    
    for (int i = 0; i < numofpassengers; i++) {
        for (int j = i; j < numofpassengers; j++) {
            if (array[i].gTotal() > array[j + 1].gTotal())
            {
                swap(array[i], array[j + 1]);
            }

        }
    }
    
    cout << "The customer is useless " << array[0].gName() << endl;
    for (int i = 0; i < numofpassengers; i++) {
        array[i] = array[i + 1];
    }
    Passengers* tempArray = new Passengers[numofpassengers];

    for (int i = 0; i < numofpassengers; i++) {
        tempArray[i] = array[i];
    }
    
    delete[] this->array;
    array = tempArray;
    numofpassengers--;
}
int main()
{
    /* tests your classes and displays the following output. you
need to add 5 passengers (not necessarily in the order shown below), display the list of
passengers (you see the list is in ascending order), remove the first passenger, display the list
again, remove another passenger, and display the list again.
This type of list of passengers is called a Priority Queue. This is not the same as Queue you
learned in this course. Regular Queues are first in first out (FIFO). But this list of passengers is
“paid less first out”. Passengers who paid less fare (purchased their ticket on sale) or
passengers who fly less frequently are considered as passengers with lower priority and must
leave before others.*/

    Flight x("28450F");

    Passengers p1("Faris", 420.69, 96);
    x.insert(p1);

    Passengers p2("Richard", 666.66, 66);
    x.insert(p2);

    Passengers p3("Raj", 999.99, 99);
    x.insert(p3);

    Passengers p4("sexlord", 777.77, 77);
    x.insert(p4);

    Passengers p5("daddy", 696.96, 969);
    x.insert(p5);

    x.display();
    cout << endl;
    cout << endl;
    x.leave();
    x.display();
    cout << endl;
    cout << endl;
    x.leave();
    x.display();

    return 0;
}


