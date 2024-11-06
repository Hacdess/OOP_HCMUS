#include "Date.h"

int main() {
	Date d1;
	Date d2;
	Date d3;
	Date d4;
	Date d5;
	Date d6;

	d1.Input();
	d2.Input();
	d3.Input();
	d4.Input();
	d5.Input();
	d6.Input();

	d6=d3;

	d6=d3.Tomorrow();
	d5=d2.Yesterday();
	
	cout<< d6 << " == " << d4 << ": " << (d6==d4) << endl;
	cout<< d6 << " != " << d4 << ": " << (d6!=d4) << endl;
	cout<< d6 << " >= " << d4 << ": " << (d6>=d4) << endl;
	cout<< d6 << " <= " << d4 << ": " << (d6<=d4) << endl;
	cout<< d6 << " > " << d4 << ": " << (d6>d4) << endl;
	cout<< d6 << " < " << d4 << ": " << (d6<d4) << endl;

	d3=d2+1;
	d2=d3-2;
	d4++;
	++d2;
	d5--;
	--d6;

	cout<< "d3: " << d3 << endl;
	cin>>d4;
	
	cout<< "From frist day of year " << d3.getYear() << " to " << d3 << ": " << (int)d3 << " days\n";			// from the first day of current year
	
	cout<< "From 1/1/1 to " << d4 << ": " <<(long)d4 << endl; 		// from 1/1/1
	Date d7;
	d7+=7;
	d2-=6;

	return 0;
}