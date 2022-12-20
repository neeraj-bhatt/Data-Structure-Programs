
//Write a program to search an element from a list. Give user the option to perform Linear or Binary search. Use Template functions.

#include<bits/stdc++.h>
using namespace std;

template<class T>
class Linear
{
    public:
        int n;
        T a;
        T *arr;

        Linear(int x)
        {
            n= x;
            arr= new T[n];
        }
        void search();
        void input();

};

template<class T>
class Binary
{
    public:
        int n;
        T a;
        T *arr;

        Binary(int x)
        {
            n= x;
            arr= new T[n];
        }
        void search();
        void input();

};

template<class T>
void Binary<T>::search()
{
    int i=n;
    int beg=0,end=i-1;
    int mid=(beg+end)/2;

    cout<<"Enter the element you want to search: "<<flush;
    cin>>a;

    while((a!=arr[mid]) && i>0)
    {
        if(a>arr[mid])
            beg=mid+1;
        else
            end=mid-1;
        mid=(beg+end)/2;
        i--;
    }

    if(a==arr[mid])
        cout<<a<<" IS FOUND AT INDEX NUMBER: "<<mid<<endl;
    else
        cout<<"-1, ELEMENT IS NOT IN THE ARRAY"<<endl;
      

}

template<class T>
void Binary<T>::input()
{
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr+a);
}

template<class T>
void Linear<T>::search()
{
    cout<<"Enter the element you want to search: ";
    cin>>a;

    int flag=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==a)
        {
            flag=1;
            cout<<a<<" IS FOUND AT INDEX NUMBER: "<<i<<endl;
            break;
        }
    }

    if(flag==0)
        cout<<"-1, ELEMENT NOT FOUND"<<endl;
}

template<class T>
void Linear<T>::input()
{
    
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];

}

int main()
{
    cout<<"Enter \n 1 for linear search \n 2 for binary search\n";
    int option = 1;
    cin>>option;

    int n;
        cout<<"Enter number of elements in the array: ";
        cin>>n;


    if(option == 1){
        Linear<int> obj(n);
        obj.input();
        obj.search();
    }else{
        Binary<int> obj(n);
        obj.input();
        obj.search();
    }
    
return 0;
}