
#include<iostream>
using namespace std;
const int size=40;
int flag=0;
/*void attain(int n)
{
 size=n;
}*/
class queues
{
      static const int size=40; 
      int front,rear;
      int queue[size];
      public:
             queues()
             {
                  front=rear=-1;
             }

             void insert(int n)
             {
              flag=0;
                  if(/*(rear-front)>(size-1))&&*/(rear==(size-1)))
                  {
                                   cout<<"overflow element can not be entered\n";
                                   flag=1;
           //return 1;
                  }
                  else if(rear<(size-1))
                  {
                      queue[++rear]=n;
                      front=0;
                      //return 0;
                  }
                  else if((rear+front)>=size)
                  {
                      for(int i=front-1;i<rear;i++)
                      queue[i]=queue[i+1];

                      queue[rear]=n;
                  }
             }

             int dlt()
             {
                  int a;
                  if((rear==-1)||(empty()==-1))
                  {
                             cout<<"underflow:\n";
                             return 0;
                  }
                  else
                  {
                      a=queue[front++];
                      cout<<"In function delete:\nfront= "<<front<<endl;
                      return a;
                  }
             }

             void display()
             {
              cout<<"In function display:\nfront= "<<front<<endl<<"rear= "<<rear<<endl;
                  for(int i=front;i<=rear;i++)
                  cout<<queue[i]<<" ";
                  cout<<endl;
             }

             int empty()
             {
                  if(front>rear)
                  return -1;
                  else
                  return 1;
             }

};