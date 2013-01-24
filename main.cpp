#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <math.h>
#include "DataPoint.h"
#include "VotePoint.h"

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
    for (int itr = 0; itr < M && getline(in, input); ++itr) {
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
                    bus->setX(atof(temp.c_str()));
                    count++;
                }
                temp = "";
            }
        }
        bus->setY(atof(temp.c_str()));
        list.push_back(bus);
        temp = "";
    }
    // Print what's in the vector for a manuel sanity check
    for (int j = 0; j < list.size(); j++) {
        cout << list.at(j)->getClass() << " " << list.at(j)->getX() << " " << list.at(j)->getY() << endl;
    }
    double x, y, avg;
    double tmpX, tmpY;
    vector<int> dist;
    do {
        avg = 0;
        cout << "Please enter X: ";
        cin >> x;
        cout << "Please enter Y: ";
        cin >> y;
        //Generate distances
        for (int n = 0; n < list.size(); n++) {
            tmpX = x - list.at(n)->getX();
            tmpX *= tmpX;
            tmpY = y - list.at(n)->getY();
            tmpY *= tmpY;
            dist.push_back(pow(tmpX + tmpY, 0.5));
        }
        
    } while( x != 1.0 || y != 1.0);
    in.close();
	return 0;
}
