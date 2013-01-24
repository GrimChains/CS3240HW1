#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "DataPoint.h"

using namespace std;

int main(int argc, char * argv[]) {
    vector< DataPoint* > list;
    int k, M;
    string name;
    if (argc == 1) { // if no commandline arguments are provided
        cout << "How many items do you want displayed?\t";
        cin >> k;
        cout << "How many values should be read?\t\t";
        cin >> M;
        cout << "Which file?\t\t\t\t";
        cin >> name;
    }
    else if (argc != 4) {
        cout << "Incorrect number of commandline arguments. Input is \"k, M, file\"" << endl;
        return 1;
    }
    else {
       k = atoi(argv[1]);
       M = atoi(argv[2]);
       name = argv[3];
    }
    ifstream in;
    in.open(name.c_str());
    string temp, input;
    int count;
    DataPoint * bus;
    while (getline(in, input)) {
        count = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != ' ') {
                temp += input[i];
            }
            else {
                if (count == 0) {
                    bus = new DataPoint();
                    bus->setClass(temp);
                    count++;
                }
                else if (count == 1) {
                    bus->setX(atoi(temp.c_str()));
                    count++;
                }
                /*else if (count == 2) {
                    bus->setY(atoi(temp.c_str()));
                    count = 0;
                }*/

                temp = "";
            }
        }
        bus->setY(atoi(temp.c_str()));
        list.push_back(bus);
        temp = "";
    }
    for (int j = 0; j < list.size(); j++) {
        cout << list.at(j)->getClass() << " " << list.at(j)->getX() << " " << list.at(j)->getY() << endl;
    }
    in.close();
	return 0;
}
