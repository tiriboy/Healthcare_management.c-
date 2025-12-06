#pragma once
#include <iostream>
#include "selectdepartment.h"
#include "getNextID.h"
#include "assign_room.h"
#include "appointmentDate.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;
struct Patient {
    int id;
    string fullName;
    int age;
    string gender;
    string address;
    string contactNumber;
    string emergencyContact;
    string status; 
    string date; 
    string room_number;
    string treatment_type;
};

void registerPatient(string filename) {
    selectDepartment(filename);  

    Patient p;
    p.id = getNextID(filename); 
    int room;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, p.fullName);
    cout << "Enter age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter gender: ";
    getline(cin, p.gender);
    cout << "Enter address: ";
    getline(cin, p.address);
    cout << "Enter contact number: ";
    getline(cin, p.contactNumber);
    cout << "Enter emergency contact: ";
    getline(cin, p.emergencyContact);
    cout <<"IF ROOM IS NEEDED ENTER 1:"<<endl;
    cin>>room;
    if(room==1){
         p.room_number= assign_room(filename);}
         else {p.room_number="NO ROOM RESERVED";}
    p.status = "In Treatment"; 
    p.date = appointmentDate(filename);


    ofstream file(filename, ios::app); 
    if (file.is_open()) {
        file << p.id << "," << p.fullName << "," << p.age << "," << p.gender << ","
             << p.address << "," << p.contactNumber << "," << p.emergencyContact << ","
             << p.status << "," << p.date <<"," <<p.room_number<< "\n";

        file.close();
        cout << "Patient registered successfully with ID: " << p.id << endl;
    } else {
        cout << "Error opening file.\n";
    }
}
