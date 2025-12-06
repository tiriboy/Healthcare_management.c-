void migratePatient(string filename) {
    selectDepartment(filename);
    string sourceFile = filename;

    string id;
    cout << "Enter patient ID to migrate: ";
    cin.ignore();
    getline(cin, id);

    ifstream file(sourceFile);
    ofstream temp("temp.csv");

    string line;
    bool found = false;
    Patient migratedPatient;

    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        getline(ss, field, ',');

        if (field == id) {
            found = true;
            migratedPatient.id = stoi(field);
            getline(ss, migratedPatient.fullName, ',');
            string age;
            getline(ss, age, ',');
            migratedPatient.age = stoi(age);
            getline(ss, migratedPatient.gender, ',');
            getline(ss, migratedPatient.address, ',');
            getline(ss, migratedPatient.contactNumber, ',');
            getline(ss, migratedPatient.emergencyContact, ',');
            getline(ss, migratedPatient.status, ',');
            getline(ss, migratedPatient.date, ',');
            getline(ss, migratedPatient.room_number, ',');
            continue;
        }

        Patient p;
        int tempID = stoi(field);
        getline(ss, p.fullName, ',');
        string age;
        getline(ss, age, ',');
        p.age = stoi(age);
        getline(ss, p.gender, ',');
        getline(ss, p.address, ',');
        getline(ss, p.contactNumber, ',');
        getline(ss, p.emergencyContact, ',');
        getline(ss, p.status, ',');
        getline(ss, p.date, ',');
        getline(ss, p.room_number, ',');

        temp << tempID << "," << p.fullName << "," << p.age << "," << p.gender << ","
             << p.address << "," << p.contactNumber << "," << p.emergencyContact << ","
             << p.status << "," << p.date << "," << p.room_number << "\n";
    }

    file.close();
    temp.close();

    if (!found) {
        cout << "Patient with ID " << id << " not found.\n";
        remove("temp.csv");
        return;
    }

    remove(sourceFile.c_str());
    rename("temp.csv", sourceFile.c_str());

    cout << "Select target department to migrate to:\n";
    selectDepartment(filename);
    string targetFile = filename;

    migratedPatient.room_number = assign_room(targetFile);

    ofstream target(targetFile, ios::app);
    if (target.is_open()) {
        target << migratedPatient.id << "," << migratedPatient.fullName << "," << migratedPatient.age << "," << migratedPatient.gender << ","
               << migratedPatient.address << "," << migratedPatient.contactNumber << "," << migratedPatient.emergencyContact << ","
               << migratedPatient.status << "," << migratedPatient.date << "," << migratedPatient.room_number << "\n";

        target.close();
        cout << "Patient migrated successfully to " << targetFile << ".\n";
        cout << "ID: " << migratedPatient.id << ", Room: " << migratedPatient.room_number << "\n";
    } else {
        cout << "Error opening target file.\n";
    }
}
