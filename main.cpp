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
            else if (temp !="") {
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
    double x, y, small;
    int n,g;
    double tmpX, tmpY;
    vector<double> dist;
    vector<double> avg;
    VotePoint * ballot;
    vector<VotePoint *> vote;
    bool flag;
    do {
        avg.clear();
        vote.clear();
        dist.clear();
        cout << "Please enter X: ";
        cin >> x;
        cout << "Please enter Y: ";
        cin >> y;
        //Generate distances
        for (n = 0; n < list.size(); n++) {
            tmpX = x - list.at(n)->getX();
            tmpX *= tmpX;
            tmpY = y - list.at(n)->getY();
            tmpY *= tmpY;
            dist.push_back(pow(tmpX + tmpY, 0.5));
        }
        small = 0;
        //Find closest guys
        for (g = 0; g < k; g++) {
            small = 0;
            for (n = 0; n < dist.size(); n++) {
                if (dist.at(small) < dist.at(n) && dist.at(n) > 0) {
                    small = n;
                }
            }
            // Probably need to store the results in a vector.
            if (dist.at(small) > 0 || g == 0) {
                // cout << list.at(small)->getClass() << " " << list.at(small)->getX() << " " << list.at(small)->getY() << endl;
                dist[small] *= -1;
                flag = false;
                // Casting our vote, or adding a new VotePoint
                for (n = 0; n < vote.size(); n++) {
                    if (list.at(small)->getClass() == vote.at(n)->getClass()) {
                        flag = true;
                        vote.at(n)->vote();
                        avg[n] += dist.at(n);
                        cout << avg[n] << endl << vote.at(n)->getClass() << endl;
                        break;
                    }
                }
                if (flag) {
                    flag = false;
                }
                else {
                    ballot = new VotePoint(list.at(small)->getClass());
                    vote.push_back(ballot);
                    avg.push_back(dist.at(small));
                    //cout << avg[n] << endl << vote.at(n)->getClass() << endl;
                }
            }
        }
        // I'm treating small as big for this loop. I know it's counter-intuitive, but it saves wasting an int
        small = 0;
        for (n = 1; n < vote.size(); n++) {
            if (vote.at(small)->getVote() < vote.at(n)->getVote()) {
                small = n;
            }
        }
        cout << "The people have voted to classify ( " << x << " , " << y << " ) as " << vote.at(small)->getClass() << endl;
        for (n = 0; n < avg.size(); n++) {
            if (avg.at(n) > 0) {
                cout << "vote: " << vote.at(n)->getVote() << endl << "n: " << n << endl;
                cout << "Average distance from " << vote.at(n)->getClass() << ":\t" << (double)avg.at(n)/(double)vote.at(n)->getVote() << endl;
            }
            else {
                cout << "vote: " << vote.at(n)->getVote() << endl << "N: " << n << endl;
                cout << "Average distance from " << vote.at(n)->getClass() << ":\t" << (double)-avg.at(n)/(double)vote.at(n)->getVote() << endl;
            }
        }
        dist.clear();
    } while( x != 1.0 || y != 1.0);
    in.close();
	return 0;
}
