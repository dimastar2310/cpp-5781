/**
 * Demonstrates memory usage in C++.
 * @author erelsgl
 */

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Point {
	private:
		int x;
		int y;
	public:
		Point() { x = y = 5555; }	
};

int main() {
	const int SIZE=125*1000*1024;

	cout << "Before new" << ' ' << endl;
	this_thread::sleep_for(chrono::seconds(3));

	Point* p = new Point[SIZE];
	for (int  i=0; i<SIZE; ++i)
		p[i] = Point();
		
	cout << "After new" << endl;
	// The free memory should drop by ... KB.

	this_thread::sleep_for(chrono::seconds(5));

	delete[] p;
}