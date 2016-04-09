/************************************************************
  FileName: 	Scan.h
  Author:       031502248
  Date:         2016/2/16
  Function:
  			处理输入数据,将其分为字符与数字 
  History:        
  <author>     <time>   <version>      <desc>
  031502248     16/3/23     2.0       修改代码规范
  031502248		16/4/4-8  	3.0		  修复减号与负号问题的bug 
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
