//Perform Queue operation using Circular Array implementation. Use templates

#include <iostream>
using namespace std;


template <typename T> class CircularArray{
    int front;
    int rear;
    int num;
    T val;
    T* arr;
    public:
    CircularArray(T arr1[], int n){
        arr = arr1;
        num = n;
        front = -1;
        rear = -1;
    }
    void enqueue(){
        cout << "Enter the Element : ";
        cin >> val;
        if(rear == -1){
            rear++;
            front++;
            arr[rear] = val;
        }
        else{
            if((rear+1)%num == front)
                cout << "Queue is full" << endl;
            else{
                rear = (rear+1)%num;
                arr[rear] = val;
            }

        }
    }
    void dequeue(){
        if(front == -1)
            cout << "Queue is Empty" << endl;
        else{
            if(front == rear){
                cout << "Element Deleted : " << arr[front] << endl;
                front = -1;
                rear = -1;
            }
            else{
                cout << "Element Deleted : " << arr[front] << endl;
                front = (front+1)%num;
            }
        }
    }
    void display(){
        int temp = front;
        bool flag = true;
        cout << "Elements : ";
        if(front = -1)
            cout << "Queue is Empty" << endl;
        else{
            do{
            cout << arr[temp] << " ";
            if(temp == rear){
                flag = false;
                break;
            }
            temp = (temp+1)%num;
            }while(temp != rear);
            if(flag)
            cout << arr[temp]; //for last element, won't run when one element in Queue
        }
        
    }
};


int main(){
    int num;
    cout << "Enter the size of array : ";
    cin >> num;
    int arr[num];
    CircularArray<int> obj(arr, num);
    int choice;
    while(true){
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << endl;
            obj.enqueue();
            break;
        case 2:
            cout << endl;
            obj.dequeue();
            break;
        case 3:
            cout << endl;
            obj.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Please Enter Correct Option" << endl;
            break;
        }
    }
    return 0;
}