#include <iostream>
using namespace std;
class Stack{
    int top;
    int count;
    public:
    Stack(){}
    Stack(int c){
        count = c;
        top = -1;
    }
    void push(int arr[], int val);
    void pop(int arr[]);
    void display(int arr[]);
};
void Stack :: push(int arr[], int val){
    if(top >= count-1)
    cout << "Stack OverFlow" << endl << endl;
    else{
        top++;
        arr[top] = val;
        cout << "Element Pushed Successfully :)" << endl << endl;
    }
}
void Stack :: pop(int arr[]){
    if(top <= -1)
    cout << "Stack UnderFlow" << endl << endl;
    else{
        cout << "Poped Element : " << arr[top] << endl << endl;
        top--;
    }
}
void Stack :: display(int arr[]){
    if(top>=0){
        cout << "-----------Elements in Stack-----------" << endl;
        for(int i=0; i<=top; i++){
            cout << arr[i] << " ";
            cout << endl;
        }
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
    Stack obj(capacity);
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