#include <iostream>
#include <string>
template <typename T>
struct node
{
	T data;
	node<T>* next;
	node(T& d,node<T>* p = NULL)
	{
		data = d;
		next = p;
	}
	void get(T& d)
	{
		d = data;
	}
};
template <typename T>
class Astack
{
	private:
		int length;
		node<T> *top;
	public:
		bool isempty()
		{
			if(length)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		Astack(int l = 0,node<T>* p = NULL)
		{
			length = l;
			top = p;
		}
		~Astack()
		{
			clear();
			std::cout<<"stack has been realsed\n";
		}
		void push(T& d)
		{
			top = new node<T>(d,top);
			++length;
		}
		void pop(T& d)
		{
			if(length == 0)
			{
				std::cout<<"It's already empty\n";
				return;
			}
			else
			{
				node<T>* temp = top;
				top = top->next;
				temp->get(d);
				delete temp;
				--length;
				return;
			}
		}
		int getlength()
		{
			return length;
		}
		void get(T& d)
		{
			top->get(d);
		}
		void clear()
		{
			if(length == 0)
			{
				return;
			}
			else
			{
				while(top)
				{
					node<T>* temp = top;
					top = top->next;
					delete temp;
					length--;
				}
				return;
			}
		}
};
template<typename T>
class Bstack
{
	private:
		T* top;
		int size;
		int length;
	public:
		int getlength()
		{
			return length;
		}
		Bstack(int s)
		{
			if(s<=0)
			{
				std::cerr<<"bad stack size\n";
				exit(1);
			}
			size = s;
			top = new T[size];
			length = 0;
		}
		~Bstack()
		{
			delete[] top;
		}
		bool isempty()
		{
			if(length)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		bool isfull()
		{
			if((size-length) == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void push(T& data)
		{
			if(isfull())
			{
				std::cout<<"can't push is full\n";
				return;
			}
			top[length++] = data;
		}
		void pop(T& data)
		{
			if(isempty())
			{
				std::cout<<"can't pop is empty\n";
				return;
			}
			data = top[--length];
		}
		void peek(T& data)
		{
			if(isempty())
			{
				std::cout<<"can't peek is empty\n";
				return;
			}
			data = top[length-1];
		}
};
template <typename T>
void selectitem(Astack<T>& s,T& n)
{
	T temp,ex;
	Astack<T> t;
	s.pop(temp);
	while(n != temp)
	{
		if(s.isempty())
		{
			std::cout<<"no such thing\n";
			return;
		}
		t.push(temp);
		s.pop(temp);
	}
	while(!t.isempty())
	{
		t.pop(ex);
		s.push(ex);
	}
	s.push(temp);
	std::cout<<"complete\n";
	return;

}
template <typename T>
void selectitem(Bstack<T>& s,T& n)
{
	T temp,ex;
	Bstack<T> t(s.getlength());
	s.pop(temp);
	while(n != temp)
	{
		if(s.isempty())
		{
			std::cout<<"no such thing\n";
			return;
		}
		t.push(temp);
		s.pop(temp);
	}
	while(!t.isempty())
	{
		t.pop(ex);
		s.push(ex);
	}
	s.push(temp);
	return;
}
//class Data
//{
//	private:
//		int num;
//		std::string name;
//		int score;
//	public:
//		Data(int n = 0,std::string a = "noname",int s = 0)
//		{
//			num = n;
//			name = a;
//			score = s;
//		}
//		void set(int n,std::string a,int s)
//		{
//			num = n;
//			name = a;
//			score = s;
//		}
//		void print()
//		{
//			std::cout<<num<<"\n"<<name<<"\n"<<score<<"\n";
//		}
//};
int main()
{
	Astack<int> stack;
	Bstack<int> stackB(3);
	int a = 1,b = 2,c = 3,d = 0;
	stack.push(a);
	stack.push(b);
	stack.push(c);
	selectitem<int>(stack,b);
	stack.pop(d);
	std::cout<<d;
	stackB.push(a);
	stackB.push(b);
	stackB.push(c);
	selectitem<int>(stackB,a);
	stackB.pop(d);
	std::cout<<d;
	return 0;

}
