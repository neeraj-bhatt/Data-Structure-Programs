
#include<iostream>
#include"Ques16(a).cpp"
using namespace std;
int main()
{
 stacks<int> s1,s2;
 char ch;
 int n;

 do
 {
  cout<<"Enter the element in the stack for reversing:\n";
  cin>>n;
  s1.push(n);
  cout<<"Want to enter more: ";
  cin>>ch;
 }while(ch=='y');
  while(s1.empty()!=-1)
  s2.push(s1.pop());
   s2.display();
}