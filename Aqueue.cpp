#include <iostream>
template <typename T>
//--------------------------------------------------
struct node
{
  T data;
  node<T> *next;
  node(const T& d,node<T>* n = NULL)
  {
    data = d;
    next = n;
  }
};
//----------------------------------------------------
//----------------------------------------------------
template <typename T>
class Aqueue
{
//-----------------------------------------------------
private:
  node<T> *front,*rear;
  int length;
//------------------------------------------------------
public:
//-------------------------------------------------------
  Aqueue()
  {
    front = NULL;
    length = 0;
    rear = NULL;
  }
//---------------------------------------------------------
  ~Aqueue()
  {
    clear();
    std::cout<<"Queue deleted\n";
  }
//---------------------------------------------------------
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
//-----------------------------------------------------------
  int getlength()
  {
    return length;
  }
//--------------------------------------------------------------
  T& head()
  {
    if(isempty())
    {
      std::cerr << "no node" << '\n';
      exit(1);
    }
    return front->data;
  }
//----------------------------------------------------------------
  void push(const T& d)
  {
    if(isempty())
    {
      front = new node<T>(d);
      rear = front;
      length = 1;
    }
    else
    {
      rear->next = new node<T>(d);
      ++length;
    }
  }
//-----------------------------------------------------------------------
  void pop()
  {
    if(isempty())
    {
      std::cerr << "Queue is already empty" << '\n';
      return;
    }
    node<T>*temp = front;
    front = front->next;
    delete temp;
    length--;
  }
//------------------------------------------------------------------------
void clear()
{
  node<T>*temp;
  while(front)
  {
    temp = front;
    front = front->next;
    delete temp;
  }
  length = 0;
}
//-----------------------------------------------------------------------
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
int main()
{
  Aqueue<int> list;
  list.push(1);
  list.push(8);
  list.push(9);
  int a = list.head();
  list.pop();
  std::cout << a << '\n';
  return 0;
}
