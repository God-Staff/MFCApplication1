#include <iostream>    
#include <boost/bind.hpp>    
#include <boost/thread/thread_pool.hpp>   
#include <boost/thread.hpp>
#include <boost/pool/pool.hpp>
using namespace std;
using namespace boost;

/**
 * @brief      { function_description }
 */
void first_task ()
{
	for (int i = 0; i < 30; ++i)
		cout << "first" << i << endl;
}

/**
 * @brief      { function_description }
 */
void second_task ()
{
	for (int i = 0; i < 30; ++i)
		cout << "second" << i << endl;
}

/**
 * @brief      { function_description }
 */
void third_task ()
{
	for (int i = 0; i < 30; ++i)
		cout << "third" << i << endl;
}

/**
 * @brief      { function_description }
 *
 * @param[in]  value  The value
 * @param[in]  str    The string
 */
void task_with_parameter (int value, string str)
{
	printf ("task_with_parameter with int=(%d).\n", value);
	printf ("task_with_parameter with string=(%s).\n", str.c_str ());
}

/**
 * @brief      { function_description }
 */
void execute_with_threadpool ()
{
	// 创建一个线程池，初始化为2个线程    
	//boost::thread_pool

	pool<boost::thread> tp(2);// (2);
	
	tp.release_memory ();
}

int main ()
{
	execute_with_threadpool ();
	return 0;
}