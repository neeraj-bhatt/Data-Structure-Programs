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

class Stack{
    Node* head;
    public:
    Stack(){
        head = NULL;
    }
    void push(int val);
    void pop();
    void display();
};

void Stack :: push(int val){
    Node* p = new Node(val);
    if(head == NULL)
        head = p;
    else{
        p->next = head;
        head = p;
    }
    cout << "Value pushed successfully" << endl;
}

void Stack :: pop(){
    Node* p;
    if(head == NULL)
        cout << "Stack Underflow condition" << endl;
    else{
        p = head;
        head = head->next;
        delete(p);
        cout << "Value poped successfully" << endl;
    }
}

void Stack :: display(){
    Node* p = head;
    cout << "Stack : ";
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
int main(){
    Stack s1;
    int choice;
    int val;
    cout << "----------Stack Operations----------" << endl;
    while(true){
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Value to Push : ";
            cin >> val;
            s1.push(val);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.display();
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