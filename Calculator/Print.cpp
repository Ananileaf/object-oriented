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
	while (que.size())   //或者用que.empty(),只要队列不为空,就一直循环下去
	{
		std::cout << que.front(); 
	}
	return ; 
}

