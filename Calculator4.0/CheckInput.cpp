#include "CheckInput.h"

CheckInput::CheckInput()
{
}

CheckInput::~CheckInput()
{
}

/*************************************************************
  functionname:   CheckIfCorrect
  Description:    判断是否出错 
  Input:          queue<string> que:输入表需要判断的达式
  Return:         string : 输出错误类型 
  Others:        			 
**************************************************************/
string CheckInput::CheckIfCorrect(queue<string> que)
{
	string ErrorType = "";
	bool flag_match = false;	//判断括号匹配是否合法 
	stack<string> sta;			//判断括号匹配需要使用到 
	queue<string> tmp = que;	

	while (!tmp.empty())		//判断括号匹配 
	{
		string data = tmp.front();
		tmp.pop();
		if (data == "(")
		{
			sta.push("(");
		}
		else if (data == ")")
		{
			if (!sta.empty())
			{
				sta.pop();
			}
			else
			{
				flag_match = true;
				break;
			}
		}
	}
		
	if (flag_match || !sta.empty())
	{
		ErrorType += "mismatch";
	}
	
	return ErrorType;
}
