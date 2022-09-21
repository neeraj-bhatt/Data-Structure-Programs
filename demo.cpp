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
void printll(Node* head)
{
    if(head == NULL)
        cout << "There is no Linked List" << endl;
    else{
        cout << "Linked List : ";
        while(head != NULL){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
} 

int main()
{
    char ch = 'Y';
    int value;
    Node* head = NULL;
    Node* ptr = NULL;
    while(ch == 'Y' || ch == 'y')
    {
        cout << "Enter a value to add in a Linked List" << endl;
        cin >>  value;
        if(head == NULL)
            head = new Node(value);
        else{
            ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new Node(value);
        }
        printll(head);
        cout << endl << "Y/y to continue" << endl;
        cin >> ch;
    }

    return 0;
}