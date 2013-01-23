#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "DataPoint.h"

using namespace std;

int main(int argc, char * argv[]) {
    vector<DataPoint> list;
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
       cout << "Name: " << name << endl;
    }
    ifstream in;
    in.open(name.c_str());
    getline(in, name, '.');
    cout << name << endl;
    in.close();
	return 0;
}
