/************************************************************
  FileName: 	fzu 1008.cpp 
  Author:       031502248
  Date:         2016/3/31
  History:        
  <author>     <time>   <version>      <desc>
  questionlink http://acm.fzu.edu.cn/problem.php?pid=1008
***********************************************************/
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string, int > job;
int main()
{
	string s;
	int salary;
	int m,n;
	cin >> m >> n ;
	for (int i = 0; i < m; i++)
	{
		cin >>s >> salary;
		job[s] = salary;
	}
	map<string,int >::iterator iter;
	int  sum = 0; 
	while (n--)
	{
		sum = 0;
		while (cin >> s)
		{
			if (s[0] == '.') break; 			
       		iter = job.find(s);
       		if( iter != job.end()) 
       		{
       			int i = job[s];
       			sum += i;
       		//	i = 0;
       		//	job[s] = i;
			   }
		}
		cout << sum <<endl; 
	}
	
}
