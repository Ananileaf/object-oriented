/************************************************************
  FileName: 	Scan.h
  Author:       031502248
  Date:         2016/2/16
  Function:
  			������������,�����Ϊ�ַ������� 
  History:        
  <author>     <time>   <version>      <desc>
  031502248     16/3/23     2.0       �޸Ĵ���淶
  031502248		16/4/4-8  	3.0		  �޸������븺�������bug 
  031502248		16/5/2		4.0		  ���Ӵ������͵��ж� 
***********************************************************/
#ifndef SCAN_H
#define SCAN_H
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#define MAXDIGIT 10
using namespace std;

class Scan
{
	public:
		Scan();
		~Scan();
		void ToStringQueue(string input); 		
		bool Judge(char temp); 
		queue<string> que;
		string ErrorType;
	private:		
};

#endif
