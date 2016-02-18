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
