#pragma once
#include <iostream>
#include "selectdepartment.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

void editPatientInfo(string filename) {
    system("cls");
    selectDepartment(filename);
    string id, output, line, newValue;
    int choice;
    bool found = false;

    cin.ignore();
    cout << "Enter patient ID to edit: ";
    getline (cin, id);

    cout << "Enter choice of attribute to edit:\n";
    cout << "1. Full Name\n" << "2. Age\n" << "3. Gender\n" << "4. Address\n" << "5. Contact Number\n";
    cout << "6. Emergency Contact\n"<< "7. Status\n" <<"8. Appointment Date\n" ;

    cout << "Enter your choice: ";
    cin >> choice;

    ifstream file(filename);
    ofstream temp("temp.csv");

    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        getline(ss, field, ',');
        string currentID = field;
        output = currentID;

        if (currentID == id) {
            found = true;
            int fieldCount = 0;
            while (getline(ss, field, ',')) {
                fieldCount++;
                output += ",";
                if (fieldCount == choice && choice==8) {
                    newValue=appointmentDate(filename);
                    output += newValue;
                }
                else if(fieldCount==choice && choice==7 ){
                      int status_choice;
                      cout<<endl;
                      cout<<"1.Complete"<<endl;
                      cout<<"2.Incomplete"<<endl;
                      cout<<"Enter choice: ";
                      cin>>status_choice;cout<<endl;
                      switch (status_choice)
                      {
                      case 1:
                        newValue="Complete";
                        output+=newValue;
                        break;
                      case 2:
                        newValue="Incomplete";
                        output+=newValue;
                        break;   
                      
                      default:
                         output+=field;
                        break;
                      }

                }
                else if(fieldCount==choice){
                       cin.ignore();
                       cout << "Enter new value: ";
                       getline(cin, newValue);
                       output+=newValue;
                }
                
                else {
                    output += field;
                }
            }
            temp << output << "\n";
        }
        else {
            temp << line << "\n";
        }
    }

    file.close();
    temp.close();
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    if (found) {
        cout << "Patient information updated successfully.\n";
    } else {
        cout << "Patient with ID " << id << " not found.\n";
    }
    cout << endl;

}