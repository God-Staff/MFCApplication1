#ifndef NOTIFY_EVENT_HPP
#define NOTIFY_EVENT_HPP
#include <iostream>
#include <vector>

/************************************************************************/
/* 用于当数据进行变更时，通知不同的处理函数                             */
/************************************************************************/

//采用委托设计模式，将其他类的数据变更处理函数，在此类下管理
class Event_Notify
{
public:
	Event_Notify () :func_vec (0),Status(0LLU) {}
	void bindfunc (std::pair<unsigned long long, void*>& FuncEvent);
	void notify ();
	void changeStatus (unsigned long long changed);
private:
	std::vector<std::pair<unsigned long long ,void*> > func_vec;//用于保存函数指针
	unsigned long long Status;
};


#endif // !NOTIFY_EVENT_HPP
