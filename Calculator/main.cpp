#include <iostream>
#include<cstdlib> 
#include"Scan.h"
#include"Print.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main()
{
	Scan a;
	Print b;
	a.ToStringQueue(a.GetString());
	b.que2=a.que;
	b.putqueue();
	system("pause");
 } 
