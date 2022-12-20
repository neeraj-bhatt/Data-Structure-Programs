//Perform Stack operation using Array Implementations. Use template

#include <iostream>
using namespace std;

template <typename T>
class Stack{
    int top;
    public:
    int count;
    Stack(){}
    Stack(int c){
        count = c;
        top = -1;
    }
    void push(T arr[], T val);
    void pop(T arr[]);
    void display(T arr[]);
};
template <typename T> void Stack<T> :: push(T arr[], T val){
    if(top >= count-1)
    cout << "Stack OverFlow" << endl << endl;
    else{
        top++;
        arr[top] = val;
        cout << "Element Pushed Successfully :)" << endl << endl;
    }
}
template <typename T> void Stack<T> :: pop(T arr[]){
    if(top <= -1)
    cout << "Stack UnderFlow" << endl << endl;
    else{
        cout << "Poped Element : " << arr[top] << endl << endl;
        top--;
    }
}
template <typename T> void Stack<T> :: display(T arr[]){
    if(top>=0){
        cout << "-----------Elements in Stack-----------" << endl;
        for(int i=0; i<=top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Stack is Empty" << endl << endl;
}
int  main()
{
    int capacity;
    int choice;
    int val;
    cout << "Enter the capacity of Stack : ";
    cin >> capacity;
    Stack<int> obj(capacity);
    int stack[capacity];
    while(true){
        cout << "Select From the following Choices" << endl;
        cout << "1.Push\n2.Pop\n3.Display\n4.exit"<< endl;
        cout << "Your Choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Element to Push : ";
                cin >> val;
                obj.push(stack, val);
                break;
            case 2:
                    obj.pop(stack);
            break;
            case 3:
                obj.display(stack);
            break;
            case 4:
                goto label;
            default:
                cout << "Enter the Correct Choice :)" << endl;
            break;
        }
    }
    label:
    
    cout << "Thank You" << endl;
    return 0;
}