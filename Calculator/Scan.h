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
***********************************************************/
#ifndef SCAN_H
#define SCAN_H
#include<queue>
#include<string>
using namespace std;
class Scan
{
	public:
		Scan();
		~Scan();
		void ToStringQueue(string input); 
		queue<string> que;
	private:
		string s;
		
};

#endif
