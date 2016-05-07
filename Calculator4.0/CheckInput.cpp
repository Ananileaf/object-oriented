#include "CheckInput.h"

CheckInput::CheckInput()
{
}

CheckInput::~CheckInput()
{
}

/*************************************************************
  functionname:   CheckIfCorrect
  Description:    �ж��Ƿ���� 
  Input:          queue<string> que:�������Ҫ�жϵĴ�ʽ
  Return:         string : ����������� 
  Others:        			 
**************************************************************/
string CheckInput::CheckIfCorrect(queue<string> que)
{
	string ErrorType = "";
	bool flag_match = false;	//�ж�����ƥ���Ƿ�Ϸ� 
	stack<string> sta;			//�ж�����ƥ����Ҫʹ�õ� 
	queue<string> tmp = que;	

	while (!tmp.empty())		//�ж�����ƥ�� 
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
