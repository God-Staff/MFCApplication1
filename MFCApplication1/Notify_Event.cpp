#include "Notify_Event.hpp"

void Event_Notify::bindfunc (std::pair<unsigned long long, void*>& FuncEvent)
{
	func_vec.push_back (FuncEvent);
}
void Event_Notify::notify ()
{
	for (auto iter=func_vec.begin();iter!=func_vec.end();++iter)
	{	//0100 1101 0011 1100
		//0000 1000 0000 0000进行异或运算
		if (Status^(iter->first))
			iter->second;
	}
}
void Event_Notify::changeStatus (unsigned long long changed)
{
	Status = Status&changed;
	notify ();
}