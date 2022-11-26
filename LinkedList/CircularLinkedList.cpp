#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(){}
    node(int v){
        val = v;
        next = NULL;
    }
};

void printll(node*head){
    node* ptr = head;
    if(head == NULL)
        cout << "There is no Linked List" << endl;
    else{
        cout << "Linked List : ";
        do{
            cout << ptr->val << " ";
            ptr = ptr->next;
        }while(ptr != head);
    }
}

int main(){
    node* head = NULL;
    node* p = NULL;
    node* ptr = NULL;
    int value;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cout << "Enter a value in Linked List : ";
        cin >> value;
        if(head == NULL){
            head = new node(value);
            head->next = head;
        }
        else{
            ptr = head;
            if(value > head->val){
                while(value > ptr->val && ptr->next != head){
                    p = ptr;
                    ptr = ptr->next;
                }
                if(value > ptr->val){
                    ptr->next = new node(value);
                    ptr->next->next = head;
                }
                else{
                    p->next = new node(value);
                    p->next->next = ptr;
                }
            }
            else{
                p = new node(value);
                p->next = head;
                while(ptr->next != head)
                    ptr = ptr->next;
                ptr->next = p;
                head = p;
            }
        }
        printll(head);
        cout << endl;
    }
}