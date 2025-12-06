#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

string appointmentDate(string filename) {
    system("cls");
    int day, month, year;
    string date;
    while (true) { 
        cout << "Enter preferred date (day month year): ";
        cin >> day >> month >> year;

        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 25) {
            cout << "Invalid date. Please try again.\n";
            continue; 
        }

        date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);

        ifstream file(filename);
        if (!file) {
            return date; 
        }

        string line;
        int count = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, fullname, age, gender, address, contactNumber, emergencyContact, status, appointmentDate;
            getline(ss, id, ',');
            getline(ss, fullname, ',');
            getline(ss, age, ',');
            getline(ss, gender, ',');
            getline(ss, address, ',');
            getline(ss, contactNumber, ',');
            getline(ss, emergencyContact, ',');
            getline(ss, status, ',');
            getline(ss, appointmentDate, ',');

            if (appointmentDate == date) {
                count++;
            }
        }

        if (count >= 30) {
            cout << "Cannot register! The date is fully booked. Enter another date.\n";
        } else {
            return date; 
        }
    }
}