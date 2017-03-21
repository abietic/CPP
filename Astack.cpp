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
class Data
{
	private:
		int num;
		std::string name;
		int score;
	public:
		Data(int n = 0,std::string a = "noname",int s = 0)
		{
			num = n;
			name = a;
			score = s;
		}
		void set(int n,std::string a,int s)
		{
			num = n;
			name = a;
			score = s;
		}
		void print()
		{
			std::cout<<num<<"\n"<<name<<"\n"<<score<<"\n";
		}
};
int main()
{
	Astack<Data> stack;
	Data a(55160513,"yhc",88),b(55160514,"sgt",98),c(55160520,"zpx",99),d;
	stack.push(a);
	stack.push(b);
	stack.push(c);
	stack.pop(d);
	return 0;

}
