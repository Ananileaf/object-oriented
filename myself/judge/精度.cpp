#include<iostream>
#include<cmath>
#include<iomanip> 
#define PI acos(-1)
using namespace std;
int main()
{
	double a=PI*10;
	cout<<a<<endl;
	cout<<setprecision(9)<<a<<endl;
	cout<<a<<endl;
//	cout<<setiosflags(ios::fixed)<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<a<<endl;
	cout<<a<<endl;
	cout<<setiosflags(ios::scientific)<<a<<endl;
	cout<<setiosflags(ios::scientific)<<setprecision(5)<<a<<endl;
 } 
