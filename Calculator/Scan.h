/************************************************************
  FileName: 	Scan.h
  Author:       031502248
  Date:         2016/2/16
  History:        
  <author>     <time>   <version>      <desc>
  03150248     16/3/23     2.0       ÐÞ¸Ä´úÂë¹æ·¶  
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
		string GetString();
		void ToStringQueue(string input); 
		queue<string> que;
	private:
		string s;
		
};

#endif
