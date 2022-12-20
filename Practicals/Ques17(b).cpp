

#include<iostream>
#include<string.h>
using namespace std;
template<class t>
class stack
{
      public:
        t data;
        stack *prev;
};
template<class t>
class stacks
{
      //int stack[size];
      stack<t> *top;
      public:
             stacks()
             {
                  top=NULL;
             }

             void push(t n)
             {
                  stack<t> *temp;
                  /*if(top==(size-1))
                  {
                                   cout<<"overflow element not entered\n";
                                   return 1;
                  }*/
                  //else
                  //{
                      temp=new stack<t>;
                      temp->data=n;
                      temp->prev=top;
                      top=temp;
                      //return 0;
                  //}
             }

             t pop()
             {
                  t a;
                  if(top==NULL)
                  {
                             cout<<"underflow:\n";
                             return -1;
                  }
                  else
                  {
                      a=top->data;
                      top=top->prev;
                      return a;
                  }
             }

             void display()
             {
                  cout<<"";
                  while(top!=NULL)
                  {
                                  cout<<top->data<<"\n^\n"<<endl;
                                  top=top->prev;
                  }
             }

             int empty()
             {
                  if(top==NULL)
                  return -1;
                  else
                  return 1;
             }

};