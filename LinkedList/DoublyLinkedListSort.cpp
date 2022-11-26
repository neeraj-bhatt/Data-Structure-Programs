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
        cout << "\nThere is no Linked List" << endl;
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
node* insertdll(node* head){
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
    return head;
}
node* deletedll(node* head){
    int value;
    char ch = 'y';
    while(ch == 'Y' || ch == 'y'){
        node* ptr = head;
        node* p = NULL;
        int i = 1;
        cout << "\nEnter a value to delete : ";
        cin >> value;
        if(value == head->val){
            head = head->next;
            if(head != NULL){head->prev = NULL;}
            delete(ptr);
            ptr = head;
            cout << "\nValue found at node-" << i << " Deleted Successfully" << endl;
        }
        else{
            while(ptr->val != value && ptr->next != NULL){
                p = ptr;
                ptr = ptr->next;
                i++;
            }
            if(ptr->next == NULL && ptr->val != value)
                cout << "\nValue not found" << endl;
            else{
                p->next = ptr->next;
                if(ptr->next != NULL){ptr->next->prev = p;}
                delete(ptr);
                ptr = p->next;
                cout << "\nValue found at node-" << i << " Deleted Successfully" << endl;
            }
        }
        cout << endl;
        printdll(head);
        if(head == NULL)
            break;
        cout << "\nEnter y to continue (anything else to exit) : ";
        cin >> ch;
    }
    return head;
}

int main(){
    int sc;
    node* head = NULL;
    while(true){
        cout << "\n----------Linked List----------" << endl;
        cout << "1. Display Linked List\n2. Insert Elements\n3. Delete Elements\n4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> sc;
        switch (sc)
        {
        case 1:
            cout << endl;
            printdll(head);
            cout << endl;
            break;
        
        case 2:
            cout << endl;
            head = insertdll(head);
            break;
        case 3:
            cout << endl;
            if(head == NULL)
                cout << "Linked List is empty" << endl;
            else{
                printdll(head);
                head = deletedll(head);
                cout << "\nAfter Deletion";
                printdll(head);
            }       
            break;
        case 4:
            cout << "\nSee you next time :)" << endl;
            exit(0);
        default:
            cout << "\nPlease Select a valid option :<" << endl;
            break;
        }
    }
    cout << endl << "--Exited Successfully--" << endl;
    return 0;
}