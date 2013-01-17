#include <iostream>
#include "DataPoint.h"

using namespace std;

int main() {
	DataPoint a;
	a.setX(3);
	a.setY(4);
	DataPoint b;
	b.setX(0);
	b.setY(0);
	cout << b.dist(a) << endl;
	return 0;
}
