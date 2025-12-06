#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

int getNextID(string filename) {
    srand(time(0));
    int id;
    bool isUnique = false;
    while (!isUnique) {
        id = (rand() % 900000) + 100000;
        ifstream file(filename);
        string line;
        isUnique = true;
        while (getline(file, line)) {
            stringstream ss(line);
            int existingID;
            ss >> existingID;
            if (existingID == id) {
                isUnique = false;
                break;
            }
        }
    }
    return id;
}
