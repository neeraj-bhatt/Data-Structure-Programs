//Perform Stack operation using Linked List Implementations

#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(){}
    Node(int v){
        val = v;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* head;
    Stack(){
        head = NULL;
    }
    void push(int value){
        Node* ptr;
        if(head == NULL)
            head = new Node(value);
        else{
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new Node(value);
        }
        cout << "Value Pushed Successfully" << endl;
    }
    void pop(){
        Node* ptr;
        Node* ptr1;
        if(head == NULL){
            cout << "Stack is Empty" << endl;
        }
        else{
            if(head->next == NULL){
                delete(head);
                head = NULL;
            }
            else{
                ptr = head;
                while(ptr->next != NULL){
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                ptr1->next = NULL;
                delete(ptr);
            }
            cout << "Value poped Successfully" << endl;
        }
    }
    // void display(){
    //     Node* temp = head;
    //     cout << "Linked List : ";
    //     while(temp!=NULL){
    //         cout << temp->val << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }
};
void printll(Node* head)
{
    if(head!=NULL){
        cout << "Stack : ";
        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}

int main()
{
    int value;
    int choice;
    Stack s1;
    while(true)
    {
        cout << "------Options------" << endl;
        cout << "1.Push\n2.Pop\n3.exit\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a value to push in Stack" << endl;
            cin >>  value;
            s1.push(value);
            //s1.display();
            printll(s1.head);
            break;
        case 2:
            s1.pop();
            //s1.display();
            printll(s1.head);
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}