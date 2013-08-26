#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
class MyQueue
{
public:
	MyQueue();
	~MyQueue();

	void push_tail(const T& node);
	T pop_head();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void MyQueue:: push_tail(const T& node)
{
	stack1.push(node);
}

template<typename T>
T MyQueue:: pop_head()
{
	if(!stack2.empty())
	{
		T cur = stack2.top();
		stack2.pop();
		return cur;
	}else{
		if(stack1.empty())
			throw new exception("empty queue");
		else{
			while(!stack1.empty())
			{
				T& tp = stack1.top();
				stack1.pop();
				stack2.push(tp);
			}
			return pop_head();
		}
	}
}

template<typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();

	void push_tail(const T& node);
	T pop_tail();
private:
	queue<T> queue1;
	queue<T> queue2;
}; 

template<typename T>
void MyStack::push_tail(const T& node)
{
	if(queue2.empty())queue1.push_back(node);
	else queue2.push_back(node);
}

template<typename T>
T MyStack:: pop_tail()
{
	if(queue1.empty())
	{
		if(queue2.empty())
			throw new exception("empty queue");
		while(queue2.size() != 1)
		{
			T& tp = queue2.top();
			queue2.pop_back();
			queue1.push_back(tp);
		}

		T& ret = queue2.top();
		queue2.pop_back();
		return ret;
	}
	if(queue2.empty())
	{
	}
}

int main()
{
	system("pause");
}