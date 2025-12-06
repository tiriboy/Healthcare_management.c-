#include <iostream>

#include "viewAllPatients.h"
#include "registerPatient.h"
#include "migratePatient.h"
#include "searchPatientByID.h"
#include "editPatientInfo.h"
#include "billingMenu.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>
using namespace std;

int serviceCharges[] = {2000, 5000, 4000, 1500};
string filename;

int main() {
    int choice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Register new patient\n";
        cout << "2. Search for a patient by ID\n";
        cout << "3. Edit patient information\n";
        cout << "4. View all patients\n";
        cout << "5. Billing\n";
        cout << "6. Migrate Patient\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: registerPatient(filename); break;
            case 2: searchPatientByID(filename); break;
            case 3: editPatientInfo(filename); break;
            case 4: viewAllPatients(filename); break;
            case 5: billingMenu(filename, serviceCharges); break;
            case 6: migratePatient(filename); break;;
            case 7: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

