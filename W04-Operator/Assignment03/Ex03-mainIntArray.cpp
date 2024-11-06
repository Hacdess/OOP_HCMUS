#include "IntArray.h"

int main() {
	// // Using dynamic allocated array
	IntArray m1;
	IntArray m2;
	
	IntArray m3;
	IntArray m4;
	IntArray m5;

	m1.Input();
	m2.Input();
	m3.Input();
	m4.Input();
	m5.Input();

	m5=m2;

	cin>>m2;
	cout<< "m2: " << m2 << endl;

	cout<< "m3[3]: " << m3[3] << endl;
	m3[4]=1;

	cout<< "Size of m4: " << (int)m4;

	return 0;
}