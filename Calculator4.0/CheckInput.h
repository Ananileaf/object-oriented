/************************************************************
  FileName: 	CheckInput.h
  Author:       031502248
  Date:         2016/5/3 
  Function:
  			  �жϱ��ʽ�Ƿ�Ϸ��Լ���ȫ������д����µı��ʽ 
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
