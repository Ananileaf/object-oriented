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
  Description:     �������string��ת��Ϊdouble����
  Input:           string temp:�����ַ���
  Return:         double data:string��Ӧ��double�������� 
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
  Description:     �������double��������Ŷ�Ӧ�����м��� 
  Input:            double Opr1:��һ�������� 
  					tring  	ch:���� 
					double Opr2:�ڶ��������� 
  Return:         double ans:�������������Ĵ� 
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
  Description:     �����ܵļ��� 
  Input:           queue<string> que: ���ֺõ��������ַ� 
  Return:     		NULL
  Others:         	NULL
**************************************************************/
void Calculation::Calculate(queue<string> que)
{
	stack<double> dig;		//���ڴ洢���� 
	stack<string> ch;		//���ڴ洢���� 
	ch.push("#");			//���ʼջ��Ϊ"#",��'#'���ȼ����,���������ȼ����ж� 
	que.push("#");			//ĩλΪ"#",���ڽ���ѭ��	
	
	while (!ch.empty())
	{
		string temp = que.front();
		que.pop();
		if (ck->JudIfChater(temp) == true) 		//�ж��Ƿ�Ϊ����
		{
			char priority =  ck->JudPrChater(ch.top(),temp);	//�Ƚ�ջ��������temp�з��ŵ����ȼ� 
			while (priority == '>')			//ջ�����ȼ������ջ���м��� 
			{
				double num2 = dig.top();	
				dig.pop();
				double num1 = dig.top();
				dig.pop();
				double Num;			
				Num = CalStrChStr(num1,ch.top(),num2);
				dig.push(Num);				//��������������ջ 
				ch.pop();
				priority = ck->JudPrChater(ch.top(),temp);
			}
			if (priority == '<')			//���ȼ�����ջ 
			{
				ch.push(temp);
				temp = "";
			}
			else if(priority == '=')		//'('')'�Լ�'#''#'���ȼ����⿼�� 
			{
				ch.pop();					//"()"��"##"����������,�������ж����ȼ�,������Ժ�ֱ�ӳ�ջ 
				temp = "";		
			}
		}
		else								//��ǰ������,ֱ����ջ 
		{
			double opr = StrToDble(temp);
			dig.push(opr);
			temp = "";
		}
	}
	
	result = dig.top();
}
