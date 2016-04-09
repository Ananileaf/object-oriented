/************************************************************
  FileName: 	JudgeRelaction.h
  Author:       031502248
  Date:         2016/4/4 
  Function:
  			配合Calculation类使用,用于分担其关于符号类型的判断
			  优先级问题等的处理 
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
