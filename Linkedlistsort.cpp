#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node() {}
    node(int v)
    {
        val = v;
        next = NULL;
    }
};

// print elements in Linked List
void printll(node *head)
{
    cout << "\n----------------------";
    if (head == NULL)
        cout << "\nThere is no Linked List";
    else
    {
        cout << "\nLinked List : ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
    cout << "\n----------------------";
    cout << endl;
}

// Insert Elements
node *insertll(node *head)
{
    cout << "\n----------------------";
    node *p = NULL;
    node *ptr = NULL;
    int value;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nEnter a value in Linked List : ";
        cin >> value;
        if (head == NULL)
            head = new node(value);
        else
        {
            if (value > head->val)
            {
                ptr = head;
                while (value > ptr->val && ptr->next != NULL)
                {
                    p = ptr;
                    ptr = ptr->next;
                }
                if (value > ptr->val)
                    ptr->next = new node(value);
                else
                {
                    p->next = new node(value);
                    p->next->next = ptr;
                }
            }
            else
            {
                p = new node(value);
                p->next = head;
                head = p;
            }
        }
        printll(head);
        cout << "\nEnter 'y' to continue (anything else to exit) : ";
        cin >> ch;
    }
    cout << "----------------------";
    return head;
}

// Delete all occurences of a value
node *deletell(node *head)
{
    node *ptr = head;
    node *p = NULL;
    int value;
    cout << "\n----------------------";
    cout << "\nEnter value to Delete : ";
    cin >> value;
    if (head == NULL)
        cout << "\nThere is no Linked list";
    while (ptr != NULL)
    {
        if (head->val == value)
        {
            head = head->next;
            delete (ptr);
            ptr = head;
        }
        else
        {
            while (value != ptr->val && ptr->next != NULL)
            {
                p = ptr;
                ptr = ptr->next;
            }
            if (ptr->next == NULL && value != ptr->val)
                ptr = NULL;
            else
            {
                p->next = ptr->next;
                delete (ptr);
                ptr = p->next;
            }
        }
    }
    cout << "\n----------------------" << endl;
    return head;
}

int main()
{
    int sc;
    node *head = NULL;
    while (true)
    {
        cout << "\n----------Linked List----------" << endl;
        cout << "1. Display Linked List\n2. Insert Elements\n3. Delete Elements\n4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> sc;
        switch (sc)
        {
        case 1:
            printll(head);
            break;

        case 2:
            head = insertll(head);
            break;
        case 3:
            printll(head);
            head = deletell(head);
            cout << "\nAfter Deletion";
            printll(head);

            break;
        case 4:
            cout << "\nSee you next time :)" << endl;
            exit(0);
        default:
            cout << "\nPlease Select a valid option :<" << endl;
            break;
        }
    }
    return 0;
}