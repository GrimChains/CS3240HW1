#ifndef DataPoint_H
#define DataPoint_H

#include <math.h>

class DataPoint {
	private:
		int x, y;
		string name;
	public:
		DataPoint( int a, int b) {
			x = a;
			y = b;
		}
		int dist(DataPoint a) {
			return sqrt(pow(x - a.getX()) + pow(y - a.getY()));
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
}

#endif
