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
	while (que.size())   //������que.empty(),ֻҪ���в�Ϊ��,��һֱѭ����ȥ
	{
		std::cout << que.front(); 
	}
	return ; 
}

