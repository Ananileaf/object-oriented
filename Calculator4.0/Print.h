/************************************************************
  FileName: 	Print.h
  Author:       031502248
  Date:         2016/5/2 
  Function:
  			��������йظ���Ŀ��Ҫ������������� 
  History:        
  <author>     <time>   <version>      <desc>
***********************************************************/
#ifndef PRINT_H
#define PRINT_H
#include<string>
#include<cstring>
#include<iostream> 
using namespace std;

class Print
{
	public:
		Print();
		~Print();
		void PrErTpye(string ErrorType);
		void PrExpression(string Expression);
		void PrResult(double Result);
	protected:
};

#endif
