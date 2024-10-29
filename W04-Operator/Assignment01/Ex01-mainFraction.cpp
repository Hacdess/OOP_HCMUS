#include "Fraction.h"

int main() {
	Fraction f1, f2;
	Fraction f3;
	Fraction f4;
	Fraction f5;
	Fraction f6, f7, f8;
	
	f1.Input();
	f2.Input();
	f3.Input();
	f4.Input();
	f5.Input();
	f6.Input();
	f7.Input();
	f8.Input();
	
	f6=f3;

	f7=f1+f5;
	f8=f2-f4;
	f2=f3*f4;
	f5=f6/f3;

	cout<<(f2==f3);
	cout<<(f3!=f1);
	cout<<(f2>=f5);
	cout<<(f2>f5);
	cout<<(f5<=f3);
	cout<<(f5<f3);


	// f1=f2+3;
	// f3=-7+f1;
	// f5=7*f3;
	// f6=f4-6;
	
	// cout<<f3;
	// cout<<f6;

	// f1+=f5;
	// f6-=f7;
	// f8*=f1;
	// f8/=f2;

	// cout<<f8++;
	// cout<<++f7;
	
	// cout<<f8--;
	// cout<<--f7;
	
	// float f=(float)f3;				// 3/2 => 1.5

	return 0;
}