#include <iostream>
using namespace std;

class CArray{
    int front;
    int rear;
    int val;
    public:
    CArray(){
        front = -1;
        rear = -1;
    }
    void insert(int arr[], int a);
    void delElement(int arr[], int a);
    void display(int arr[], int a);
};
void CArray :: insert(int arr[], int a){
    cout << "Enter the Element : ";
    cin >> val;
    if(rear == -1){
        rear++;
        front++;
        arr[rear] = val;
    }
    else{
        if((rear+1)%a == front)
            cout << "Queue is Full" << endl;
        else{
            rear = (rear+1)%a;
            arr[rear] = val;
        }
    }
}

void CArray :: delElement(int arr[], int a){
    if(front == -1)
        cout << "Queue is Empty" << endl;
    else{
        if(front == rear){
            cout << "Deleted Element : " << arr[front];
            front = -1;
            rear = -1;
        }
        else{
            cout << "Deleted Element : " << arr[front];
            front = (front+1)%a;
        }
    }
}

void CArray :: display(int arr[], int a){
    int c = front;
    bool flag = true;
    if(front == -1)
        cout << "Queue is Empty" << endl;
    else{
        cout << "Elements in Queue : ";
        do{
            cout << arr[c] << " ";
            if(front == rear){
                flag = false;
                break;
            }
            c = (c+1)%a;
        }while(c != rear);
        if(flag)
            cout << arr[c]; //last Element, won't run when 1 element in Queue
    }
}
int main(){
    int num;
    cout << "Enter the size of array : ";
    cin >> num;
    int arr[num];
    CArray obj;
    int choice;
    while(true){
        cout << "\n1.Insert\t2.Delete\t3.Show\t4.Display";
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        switch(choice){
        case 1:
            cout << endl;
            obj.insert(arr, num);
            break;
        case 2:
            cout << endl;
            obj.delElement(arr, num);
            break;
        case 3:
            cout << endl;
            obj.display(arr, num);
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