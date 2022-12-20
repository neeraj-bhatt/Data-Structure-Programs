//Write a program using templates to sort a list of elements. Give user the option to perform sorting using Insertion sort, Bubble sort or Selection sort.

#include<iostream>
using namespace std;
template <class X_Type> class SortingOfArray
{
    public:
        X_Type *arr;
        int size;
        X_Type temp , a , b ;
        X_Type input();
        X_Type choice();
        X_Type selection_sort();
        X_Type bubble_sort();
        X_Type insertion_sort();
};


    template <class X_Type> X_Type SortingOfArray<X_Type> :: choice()
{
    int c;
    char ch;
    SortingOfArray<int> a;
    SortingOfArray<char> b;
    SortingOfArray<float> f;

        
do
{
        cout<<"1. For Integer type "<<endl;
        cout<<"2. For Character type "<<endl;
        cout<<"3. For float type "<<endl;
        cout<<endl<<"Enter your choice : ";
        cin>>c;
        
        
        switch(c)
                {
                        case 1 :
                    {
                        a.input();
                        a.selection_sort();
                        break;
                    }
                    
                        case 2 :
                    {    
                        b.input();
                        b.bubble_sort();
                        break;
                    }
                    
                        case 3 :
                    {
                        f.input();
                        f.insertion_sort();
                        break;
                    }
                        
                    default : cout<<"Enter correct choice "<<endl;
            }
            
            
                    cout<<endl<<"Do you want to continue for other data types press (y/n) "<<endl;
                    cin>>ch;
    }
                while(ch=='y' || ch=='Y');
}

    template <class X_Type> X_Type SortingOfArray<X_Type> :: input()
        {
            
            cout<<"Enter the size of an array : "<<" ";
            cin>>size;
            arr=new X_Type[size];
            cout<<"Enter the element of array : "<<endl;
            for(int i=0;i<size;i++)
            {
                cin>>arr[i];
            }
            
            
        }
        
 
//selection sort
     template <class X_Type> X_Type SortingOfArray<X_Type> ::selection_sort()
        {
            
            
            for(int i=0;i<size;i++)
            {
            temp = arr[i];
            a = i;
            for(int j=i+1;j<size;j++)
            {
                if(arr[j]<temp)
                {
                    temp=arr[j];
                    a=j;
                }
            }
            b = arr[i];
            arr[i] = arr[a];
            arr[a] = b;
        }
        
        cout<<"Sorted array is : ";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
}

//bubble sort
        template <class X_Type> X_Type SortingOfArray<X_Type> :: bubble_sort()
    {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size-1-i;j++)
                {
                    if(arr[j]>=arr[j+1])
                    {
                        b = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = b;
                    }
                }
            }
            cout<<"Sorted array is : ";
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
}

//insertion sort
        template <class X_Type> X_Type SortingOfArray<X_Type> :: insertion_sort()
    {
        for(int i=1;i<size;i++)
        {
            temp=arr[i];
            int j=i-1;
            while((arr[j]>temp)&&(j>=0))
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1]=temp;
            }
            
            cout<<"Sorted array is : ";
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
}

int main()
{
    int c;
    char ch;
        do
        {
            cout<<"Press 1 for selection sort --"<<endl;
            cout<<"Press 2 for bubble sort --"<<endl;
            cout<<"Press 3 for insertion sort --"<<endl;
            cout<<endl<<"Enter your choice : ";
            cin>>c;
            switch(c)
            {
            case 1:
                {
                    SortingOfArray<int>ob1;
                    ob1.choice();
                    
                
                    break;
                }
            case 2:
                {
                    SortingOfArray<int>ob2;
                    ob2.choice();
                
                
                    break;
                }
            case 3:
                {
                    SortingOfArray<int>ob3;
                    ob3.choice();
                
                
                    break;
                }
            default:
                cout<<endl<<"!!!!!!Wrong choice"<<endl;
                break;
        }
        cout<<endl<<"Do you want to continue for sorting by other types , enter (y/e/s) : " ;
        cin>>ch;
    }while(ch=='y'||ch=='e'||ch=='s');
    return 0;
}