#include "Calculation.h"
#include "JudgeRelaction.h"

Calculation::Calculation()
{
	ck = new JudgeRelaction;
}

Calculation::~Calculation()
{
	delete ck;
}


/*************************************************************
  functionname:    StrToDble
  Description:     将输入的string类转变为double类型
  Input:           string temp:输入字符串
  Return:         double data:string对应的double类型数据 
  Others:         NULL
**************************************************************/
double Calculation::StrToDble(string temp)
{
	stringstream stream;
	stream.clear();
	stream << temp;
	double data;
	stream >> data;
	return data;
}

/*************************************************************
  functionname:    CalStrChStr
  Description:     将输入的double类型与符号对应来进行计算 
  Input:            double Opr1:第一个操作数 
  					tring  	ch:符号 
					double Opr2:第二个操作数 
  Return:         double ans:进行四则运算后的答案 
  Others:         NULL
**************************************************************/
double Calculation::CalStrChStr(double Opr1,string ch,double Opr2)
{

	double ans;
	if (ch == "+")
	{
		ans = Opr1 + Opr2;
		return ans;
	}
	else if (ch == "-")
	{
		ans = Opr1 - Opr2;
		return ans;
	}
	else if (ch == "*")
	{
		ans = Opr1 * Opr2;
		return ans;
	}
	else if (ch == "/")
	{
		ans = Opr1 / Opr2;
		return ans;
	}
}

/*************************************************************
  functionname:    Calculate
  Description:     进行总的计算 
  Input:           queue<string> que: 区分好的数字与字符 
  Return:     		NULL
  Others:         	NULL
**************************************************************/
void Calculation::Calculate(queue<string> que)
{
	stack<double> dig;		//用于存储数字 
	stack<string> ch;		//用于存储符号 
	ch.push("#");			//最初始栈低为"#",令'#'优先级最低,用来简化优先级的判断 
	que.push("#");			//末位为"#",用于结束循环	
	
	while (!ch.empty())
	{
		string temp = que.front();
		que.pop();
		if (ck->JudIfChater(temp) == true) 		//判断是否为符号
		{
			char priority =  ck->JudPrChater(ch.top(),temp);	//比较栈顶符号与temp中符号的优先级 
			while (priority == '>')			//栈顶优先级高则出栈进行计算 
			{
				double num2 = dig.top();	
				dig.pop();
				double num1 = dig.top();
				dig.pop();
				double Num;			
				Num = CalStrChStr(num1,ch.top(),num2);
				dig.push(Num);				//将计算结果入数字栈 
				ch.pop();
				priority = ck->JudPrChater(ch.top(),temp);
			}
			if (priority == '<')			//优先级低入栈 
			{
				ch.push(temp);
				temp = "";
			}
			else if(priority == '=')		//'('')'以及'#''#'优先级特殊考虑 
			{
				ch.pop();					//"()"与"##"不参与运算,仅用于判断优先级,所以配对后直接出栈 
				temp = "";		
			}
		}
		else								//当前是数字,直接入栈 
		{
			double opr = StrToDble(temp);
			dig.push(opr);
			temp = "";
		}
	}
	
	result = dig.top();
}
