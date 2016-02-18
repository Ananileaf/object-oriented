#include "Print.h"
#include<iostream>
Print::Print()
{
	
}

Print::~Print()
{
}

void Print::putqueue()
{
	while(que2.size())
	{
		std::cout<<que2.front()<<endl;	 
		que2.pop();
	}

}
