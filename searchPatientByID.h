#pragma once
#include <iostream>
#include "selectdepartment.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;
void searchPatientByID(string filename) {
    selectDepartment(filename);  

    string id;
    cout << "Enter patient ID to search: ";
    cin.ignore();
    getline(cin, id);

    ifstream file(filename);
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        getline(ss, field, ',');
        if (field == id) {
            found = true;
            cout << "\n--- Patient Found ---\n";
            cout << "ID: " << field << endl;

            string labels[] = {"Full Name", "Age", "GENDER", "Address", "Contact Number",
                "EMERGENCY CONTACT", "Status", "Appointment DATE","ROOM_NUMBER"};
                for (int i = 0; i < 9; i++) {
                    getline(ss, field, ',');
                    if (field.empty()) {
                        field = "N/A";

                    }
                    cout << labels[i] << ": " << field << endl;
                }
                if (filename == "general_medicine.csv") {
            cout << "department:GENERAL_MEDICINE" << endl;

        }
        if (filename == "surgery.csv" ) {
            cout << "department:SURGERY" << endl;

        }
        if (filename == "orthopedics.csv" ) {
            cout << "department:ORTHOPEDICS" << endl;

        }
        if (filename == "pediatrics.csv") {
            cout << "department:PEDIATRICS" << endl;

        }
            break;
        }
    }
    if (found == false) {
        cout << "Patient with ID " << id << " not found.\n";
    }
    file.close();
}
