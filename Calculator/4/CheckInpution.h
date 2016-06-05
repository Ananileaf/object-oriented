#pragma once
/************************************************************
FileName: 	CheckInpution.h
Author:       031502248
Date:         2016/5/3
Function:
判断表达式是否合法以及补全部分手写情况下的表达式
History:
<author>     <time>   <version>      <desc>
***********************************************************/
#include<queue>
#include<string>
#include<stack>
using namespace std;

class CheckInpution
{
public:
	CheckInpution();
	~CheckInpution();
	string CheckIfCorrect(queue<string> que);
protected:
};

