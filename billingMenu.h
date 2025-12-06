#pragma once
#include <iostream>
#include "selectdepartment.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

void billingMenu(string filename, int serviceCharges[]) {
    system("cls");
    selectDepartment(filename);  

    int id, days = 0;
    cout << "Enter patient ID for billing: ";
    cin >> id;

    
    ifstream file(filename);
    string line;
    bool found = false;
    ofstream temp("temp.csv");

    while (getline(file, line)) {
        stringstream ss(line);
        string Patient_id;
        getline(ss, Patient_id, ',');
        int currentID = stoi(Patient_id);

        if (currentID == id) {
            found = true;
            string room;
            string status="Complete";

            for (int i = 1; getline(ss, room, ','); i++) {
                if (i == 9) {
                    if (room=="NO ROOM RESERVED") {
                        days=0;
                    }else{
                        cout<<"Enter number of days stayed: ";
                        cin>>days;
                     }
                } 
            }
            


            int departmentIndex = filename == "general_medicine.csv" ? 0 :
                                  filename == "surgery.csv" ? 1 :
                                  filename == "orthopedics.csv" ? 2 : 3;
            int totalBill = serviceCharges[departmentIndex] + (days * 100);  

            cout << "Total Bill: $" << totalBill << endl;

          
            temp << currentID << ",";
            stringstream ss2(line);
            string status_update;
            getline(ss2, status_update, ',');

            for (int i = 1; getline(ss2, status_update, ','); i++) {
                
                if(i==9){
                     temp<<"NO ROOM RESERVED";

                }
                
                else if (i == 7) {
                    temp << "Completed,"; 
                } else {
                    temp << status_update << ",";
                }
            }
            temp << "\n";
        } else {
            temp << line << "\n"; 
        }
    }

    file.close();
    temp.close();

    if (found) {
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());
        cout << "Patient status updated to 'Completed' and billing finalized.\n";
    } else {
        cout << "Patient with ID " << id << " not found.\n";
    }
}