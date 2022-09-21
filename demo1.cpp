#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(){}
    Node(int v){
        val = v;
        next = NULL;
    }
};

void printll(Node* head)
{
    if(head == NULL)
        cout << "There is no Linked List" << endl;
    else
    {
        while(head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* ptr = NULL;
    char ch = 'y';
    int value;
    while(ch == 'y' || ch == 'Y')
    {
        cout << "Enter a value in linked list" << endl;
        cin >> value;
        if(head == NULL)
            head = new Node(value);
        else{
            ptr = new Node(value);
            ptr->next = head;
            head = ptr;
        }
        cout << "Linked List : ";
        printll(head);
        cout << endl << "Y/y to continue" << endl;
        cin >> ch;
    }
    return 0;
}