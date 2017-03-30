#ifndef NOTIFY_EVENT_HPP
#define NOTIFY_EVENT_HPP
#include <iostream>
#include <vector>

/************************************************************************/
/* ���ڵ����ݽ��б��ʱ��֪ͨ��ͬ�Ĵ�����                             */
/************************************************************************/

//����ί�����ģʽ��������������ݱ�����������ڴ����¹���
class Event_Notify
{
public:
	Event_Notify () :func_vec (0),Status(0LLU) {}
	void bindfunc (std::pair<unsigned long long, void*>& FuncEvent);
	void notify ();
	void changeStatus (unsigned long long changed);
private:
	std::vector<std::pair<unsigned long long ,void*> > func_vec;//���ڱ��溯��ָ��
	unsigned long long Status;
};


#endif // !NOTIFY_EVENT_HPP
