#include <iostream>
#include "Queue.h"

int main() {
    Queue<string> takeoff,landing;
    string key,flightNo,type;
    cout << "Enter New, Available, Quit: ";
    getline(cin,key);
    do {
        if(key == "New")
        {
            cout << "Flight no? ";
            getline(cin,flightNo);
            cout << "Land or Take-off? ";
            getline(cin,type);
            if(type == "Land")
                landing.insert(flightNo);
            else if(type == "Take-off")
                takeoff.insert(flightNo);
        }

        else if(key == "Available")
        {
            if(!landing.isEmpty())
            {
                cout << landing.deleteQ() << " is authorized to land.\n";
            }
            else if(!takeoff.isEmpty())
            {
                cout << takeoff.deleteQ() << " is authorized to take off.\n";
            }
            else
                cout << "No planes are waiting\n";

        }
        cout << "Enter New, Available, Quit: ";
        getline(cin,key);

    }while(key!="Quit");
}
