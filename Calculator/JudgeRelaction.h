/************************************************************
  FileName: 	JudgeRelaction.h
  Author:       031502248
  Date:         2016/4/4 
  Function:
  			���Calculation��ʹ��,���ڷֵ�����ڷ������͵��ж�
			  ���ȼ�����ȵĴ��� 
  History:        
  <author>     <time>   <version>      <desc>
***********************************************************/
#ifndef CHECKRELACTION_H
#define CHECKRELACTION_H
#include<string>
#include<map>
#include<iostream>
using namespace std;
class JudgeRelaction
{
	public:
		JudgeRelaction();
		~JudgeRelaction();
		bool JudIfChater(string ch);
		char JudPrChater(string op1,string op2);
	private:
		char OprRelation[7][7];
		map<string,int> p;
};

#endif
