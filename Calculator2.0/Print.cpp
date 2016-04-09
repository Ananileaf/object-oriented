#include "Print.h"
#include<iostream>
Print::Print()
{

}

Print::~Print()
{
}

/*************************************************************
  functionname:    putqueue
  Description:     输出类中私有成员变量中的queue类中的元素 
  Input:           NULL
  Return:          no return 
  Others:          NULL
**************************************************************/
void Print::putqueue()
{
	while (!que.empty())
	{
		std::cout << que.front() << endl; 
		que.pop(); 
	}
	return ; 
}

