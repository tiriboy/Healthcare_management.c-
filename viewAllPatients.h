#pragma once
#include <iostream>
#include "selectdepartment.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

void viewAllPatients(string filename) {
    selectDepartment(filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found or error opening file.\n";
        return;
    }

    string line;

    cout << "\n--- List of Patients ---\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Full Name"
         << setw(5) << "Age"
         << setw(10) << "Gender"
         << setw(20) << "Address"
         << setw(20) << "Contact No"
         << setw(20) << "Emergency No"
         << setw(20) << "Status"
         << setw(12) << "Date"
         << setw(15) << "Room No" << endl;

    cout << string(160, '-') << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        int column = 0;

        while (getline(ss, item, ',')) {
            switch (column) {
                case 0: cout << left << setw(10) << item; break;
                case 1: cout << left << setw(20) << item; break;
                case 2: cout << left << setw(5) << item; break;
                case 3: cout << left << setw(10) << item; break;
                case 4: cout << left << setw(20) << item; break;
                case 5: cout << left << setw(20) << item; break;
                case 6: cout << left << setw(20) << item; break;
                case 7: cout << left << setw(20) << item; break;
                case 8: cout << left << setw(12) << item; break;
                case 9: cout << left << setw(15) << item; break;
                default: cout << item << " "; break;
            }
            column++;
        }
        cout << endl;
    }

    file.close();
}
