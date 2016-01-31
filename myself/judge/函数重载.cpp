#include<iostream>
using namespace std;
 
int max(int a,int b)
{
	return a>b?a:b; 
}
double max(double a,double b)
{
	return a>b?a:b; 
}
int main()
{
	int i1,i2;
	cin>>i1>>i2;
	cout<<"i_max="<<max(i1,i2)<<endl;	
	
	double d1,d2;
	cin>>d1>>d2; 	
	cout<<"d_max="<<max(d1,d2)<<endl;
 } 

