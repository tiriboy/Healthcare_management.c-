#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;
void selectDepartment(string &filename){
    system("cls");
    int departmentChoice = 0;
    cout << "Select Department:\n";
    cout << "1. General Medicine\n";
    cout << "2. Surgery\n";
    cout << "3. Orthopedics\n";
    cout << "4. Pediatrics\n";
    cout << "Enter your choice: ";
    cin >> departmentChoice;

    switch (departmentChoice) {
        case 1: filename = "general_medicine.csv"; break;
        case 2: filename = "surgery.csv"; break;
        case 3: filename = "orthopedics.csv"; break;
        case 4: filename = "pediatrics.csv"; break;
        default:
            cout << "Invalid choice. Defaulting to General Medicine.\n";
            filename = "general_medicine.csv";
    }
    system("cls");
}