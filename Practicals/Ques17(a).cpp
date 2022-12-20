
//Write a program to reverse the order of the elements in the stack using additional Queue.
        
#include<iostream>
#include"Ques17(b).cpp"
#include"Ques17(c).cpp"
using namespace std;
int main()
{
 stacks<int> s1;
 int s[100],n;
 queues q1;
 char ch;

 do
 {
  cout<<"Enter the element in the stack:\n";
  cin>>n;
  s1.push(n);
  //temp++;
  cout<<"Want to enter more: ";
  cin>>ch;
 }while(ch=='y');
 //attain(temp);
  while(s1.empty()!=-1)
  q1.insert(s1.pop());
 while(q1.empty()!=-1)   s1.push(q1.dlt());
   cout<<"The resulting reversed stack is:\n";
 s1.display();
 }