#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(){}
    Node(int v)
    {
        val = v;
        next = NULL;
    }
};

void printll(Node* head){
    if(head == NULL)
        cout << "There in no Linked List";
    else{
        cout << "Linked List : ";
        while(head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}
int main()
{
    int value;
    char ch = 'y';
    Node* head = NULL;
    Node* ptr = NULL;
    Node* ptr1 = NULL;
    while(ch == 'Y' || ch == 'y')
    {
        cout << "Enter a value in Linked List" << endl;
        cin >> value;
        if(head == NULL)
            head = new Node(value);
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
                    ptr->next = new Node(value);
                else{                 //for adding new node anywhere between Linked list
                    ptr1->next = new Node(value);
                    (ptr1->next)->next = ptr;
                }

            }
            //when value is less than head->value
            //node is added at beginning and head is now pointing to new starting node
            else{
                ptr = new Node(value);
                ptr->next = head;
                head = ptr;
            }
        }
        printll(head);
        cout << endl << "Enter 'y/Y to continue or anything else to exit" << endl;
        cin >> ch;
        
    }

    return 0;
}