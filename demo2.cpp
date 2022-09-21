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
            if(value >= head->val)
            {
                ptr = head;
                while(value > ptr->val && ptr->next != NULL)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                if(value > ptr->val)
                    ptr->next = new Node(value);
                else{
                    ptr1->next = new Node(value);
                    (ptr1->next)->next = ptr;
                }
                // ptr1 = new Node(value);
                // head->next = ptr1;
            }
            else if(value < head->val){
                ptr = new Node(value);
                ptr->next = head;
                head = ptr;
            }
            else{
                cout << "There is some error" << endl;
                exit;
            }
        }
        printll(head);
        cout << endl << "Enter 'y/Y to continue" << endl;
        cin >> ch;
        
    }

    return 0;
}