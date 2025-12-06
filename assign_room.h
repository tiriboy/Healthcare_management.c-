#pragma once
#include <iostream>
#include "selectdepartment.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;
string assign_room(string filename) {
    system("cls");
    set<int> occupiedRooms;

    int start, end;
    if (filename == "general_medicine.csv") {
        start = 1; end = 99;
    } else if (filename == "surgery.csv") {
        start = 100; end = 199;
    } else if (filename == "orthopedics.csv") {
        start = 200; end = 299;
    } else if (filename == "pediatrics.csv") {
        start = 300; end = 399;
    }

    ifstream file(filename);
    if(file.is_open()){
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string field, lastField;

            while (getline(ss, field, ',')) {
                lastField = field;
            }

            if (lastField != "NO ROOM RESERVED" && lastField != "")  {
                occupiedRooms.insert(stoi(lastField));
            }
        }
        file.close();

        for (int room = start; room <= end; room++) {
        if(occupiedRooms.find(room) == occupiedRooms.end()) {
                return to_string(room);
            }
        }

        cout << "All rooms are reserved" << endl;
        return "NO ROOM RESERVED";
    }
        
    else{


        cout<<"File was not opened successfully for reading rooms"<<endl;
        return "";
    
    
    
    }
  
}
