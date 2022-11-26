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

void printll(node* head){
    node* ptr = head;
    if(head == NULL)
        cout << "There in no Linked List" << endl;
    else{
        cout << "Linked List : ";
        while(ptr != NULL)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
node* del(node* head, int value){
    node* ptr1 = head;
    if(head == NULL)
        cout << "There is nothing to Delete" << endl;
    else{
        while(ptr1 != NULL)
        {        
            if(head->val == value){
                head = head->next;
                delete(ptr1);
                ptr1 = head;
            }
            else{
                node* p = head;
                while(ptr1->val != value && ptr1->next != NULL){
                    p = ptr1;
                    ptr1 = ptr1->next;
                }
                if(ptr1->next == NULL && ptr1->val != value)
                    ptr1 = NULL;
                else{
                    p->next = ptr1->next;
                    delete(ptr1);
                    ptr1 = p->next;
                }
            }
        }
    }
    return head;
}

int main()
{
    int value;
    char ch = 'y';
    node* head = NULL;
    node* ptr = NULL;
    node* ptr1 = NULL;
    while(ch == 'Y' || ch == 'y')
    {
        cout << "Enter a value in Linked List" << endl;
        cin >> value;
        if(head == NULL)
            head = new node(value);
        else{
            if(value > head->val)
            {
                ptr = head;
                while(value > ptr->val && ptr->next != NULL)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                if(value > ptr->val)  //for adding new node at the end
                    ptr->next = new node(value);
                else{                 //for adding new node anywhere between Linked list
                    ptr1->next = new node(value);
                    (ptr1->next)->next = ptr;
                }

            }
            //when value is less than head->value
            //node is added at beginning and head is now pointing to new starting node
            else{
                ptr = new node(value);
                ptr->next = head;
                head = ptr;
            }
        }
        printll(head);
        cout << endl << "Enter 'y/Y to continue or anything else to exit" << endl;
        cin >> ch;
        
    }
    cout << "For Deletion, Enter y : " << endl;
    cin >> ch;
    while(ch == 'y' || ch == 'Y'){
        printll(head);
        cout << endl << "Enter a value to delete : " << endl;
        cin >> value;
        head = del(head, value);
        cout << "After Deletion" << endl;
        printll(head);
        cout << "Enter y to continue : ";
        cin >> ch;
    }

    return 0;
}