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
  Description:     �������˽�г�Ա�����е�queue���е�Ԫ�� 
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

