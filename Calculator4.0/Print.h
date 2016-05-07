/************************************************************
  FileName: 	Print.h
  Author:       031502248
  Date:         2016/5/2 
  Function:
  			输出所有有关该项目需要输出的所有内容 
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
