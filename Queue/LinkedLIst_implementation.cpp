#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){}
    Node(int v){
        data = v;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
    }
    void enqueue(int val){
        if(head == NULL){
            head = new Node(val);
            tail = head;
        }
        else{
            tail->next = new Node(val);
            tail = tail->next;
        }
        cout << "Value enqueued successfully" << endl;
    }
    void dequeue(){
        Node* p;
        if(head == NULL)
            cout << "Queue is empty";
        else{
            p = head->next;
            delete(head);
            head = p;
            cout << "Value dequeued successfully";
        }
        cout << endl;
    }
    void display(){
        Node* p = head;
        cout << "Queue : ";
        if(head == NULL)
            cout << "Empty";
        else{
            while(p!=NULL){
                cout << p->data << " ";
                p = p->next;
            }
        }
        cout << endl;
    }
};
int main(){
    Queue q1;
    int choice;
    int val;
    cout << "----------Queue Operations----------" << endl;
    while(true){
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Value to Enqueue : ";
            cin >> val;
            q1.enqueue(val);
            break;
        case 2:
            q1.dequeue();
            break;
        case 3:
            q1.display();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Wrong chocie" << endl;
            break;
        }
    }
    return 0;
}