/************************************************************
  FileName: 	CheckInput.h
  Author:       031502248
  Date:         2016/5/3 
  Function:
  			  判断表达式是否合法以及补全部分手写情况下的表达式 
  History:        
  <author>     <time>   <version>      <desc>
***********************************************************/
#ifndef CHECKINPUT_H
#define CHECKINPUT_H
#include<queue>
#include<string>
#include<stack>
using namespace std;

class CheckInput
{
	public:
		CheckInput();
		~CheckInput();
		string CheckIfCorrect(queue<string> que);
	protected:
};

#endif
