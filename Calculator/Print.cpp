#include "Print.h"
#include<iostream>
Print::Print() {

}

Print::~Print() {
}

void Print::putqueue() {
	while(que.size()) { //或者用.empty(),只要队列不为空,就一直循环下去
		std::cout<<que.front()<<endl;	//输出
		que.pop();//输出一个后，清空一个；
	}

}
