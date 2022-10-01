#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* prev;
    node* next;
    node(){}
    node(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
};

void printdll(node* head){
    node* p = NULL;
    if(head == NULL)
        cout << "There is no Linked List" << endl;
    else{
        cout << "Linked List (next) : ";
        while(head != NULL){
            cout << head->val << " ";
            p = head;
            head = head->next;
        }
        cout << endl << "Linked List (prev) : ";
        while(p != NULL){
            cout << p->val << " ";
            p = p->prev;
        }
    }
    
}

int main(){
    node* head = NULL;
    node* ptr;
    int value;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        cout << endl << "Enter a value in Doubly Linked List : ";
        cin >> value;
        if(head == NULL)
            head = new node(value);
        else{
            if(value > head->val){
                ptr = head;
                while(value > ptr->val && ptr->next != NULL)
                    ptr = ptr->next;

                if(value > ptr->val){
                    ptr->next = new node(value);
                    (ptr->next)->prev = ptr;
                }
                else{
                (ptr->prev)->next = new node(value);
                ((ptr->prev)->next)->next = ptr;
                ((ptr->prev)->next)->prev = ptr->prev;
                ptr->prev = (ptr->prev)->next;
                }

            }
            else{
                head->prev = new node(value);
                (head->prev)->next = head;
                head = head->prev;
            }
        }
        printdll(head);
        cout << endl << endl << "Enter y to continue (anything else to exit) : ";
        cin >> ch;
    }
    cout << endl << "--Exited Successfully--" << endl;
    return 0;
}