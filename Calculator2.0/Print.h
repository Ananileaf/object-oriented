/************************************************************
  FileName: 	Print.h
  Author:       031502248
  Date:         2016/2/16
  History:        
  <author>     <time>   <version>      <desc>
  03150248     16/3/23     2.0       ÐÞ¸Ä´úÂë¹æ·¶  
***********************************************************/
#ifndef PRINT_H
#define PRINT_H
#include "Scan.h"
class Print :Scan
{
	public:
		Print();
		~Print();
		queue<string> que;
		void putqueue(); 
	protected:
};

#endif
