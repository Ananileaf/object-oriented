/************************************************************
  FileName: 	Calculation.h
  Author:       031502248
  Date:         2016/4/4 
  Function:
  				����string��Ϊ�洢��ʽ��ʽ�ӽ��м��� 
  History:        
  <author>     <time>   <version>      <desc>
  031502248		16/5/2  	2.0			���ļ������������ʽ 
***********************************************************/
#ifndef CALCULATION_H
#define CALCULATION_H
#include "JudgeRelaction.h"
#include<iostream>
#include<cstring>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Calculation
{
	public:
		Calculation();
		~Calculation();
		void Calculate(queue<string> que);
		double CalStrChStr(double Opr1,string ch,double Opr2);
		double StrToDble(string temp);
		double result;
	private:
		JudgeRelaction *ck;

};

#endif
