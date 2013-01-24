#ifndef DataPoint_H
#define DataPoint_H

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class DataPoint {
	private:
		double x, y;
		string name;
	public:
		DataPoint() {
            x = 0;
            y = 0;
            name = "";
        }
        DataPoint( int a, int b, string in) {
			x = a;
			y = b;
			name = in;
		}
		int dist(DataPoint a) {
			return sqrt(pow((x - a.getX()), 2) + pow((y - a.getY()), 2));
		}
		double getX() {
			return x;
		}
		double getY() {
			return y;
		}
		string getClass() {
			return name;
		}
		void setX(double a) {
			x = a;
		}
		void setY(double b) {
			y = b;
		}
		void setClass(string in) {
			name = in;
		}
};

#endif
