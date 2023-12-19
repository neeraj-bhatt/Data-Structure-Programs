#include <iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(){}
    node(int v){
        val = v;
        this->next = NULL;
    }
};

class linkedList{
    node* head = NULL;
    node* tail = NULL;
    public:
    //default constructor
    linkedList(){}
    // takes an array and it's size to get a linked list
    linkedList(int* arr, int size);
    void insert(int val);
    void deletion(void);            
    void printll(void);
};

linkedList :: linkedList(int* arr, int size){
    if(arr != NULL){
        head = new node(arr[0]);
        tail = head;
        int arrsize = size/sizeof(int);
        int num = 1;
        while(num < arrsize){
            tail->next = new node(arr[num]);
            tail = tail->next;
            num++;
        }
    }
    else{
        cout << "Array is empty" << endl;
    }
}

// inserts new elements in the end
void linkedList :: insert(int val){
    if(head == NULL){
        head = new node(val);
        tail = head;
    }
    else{
        tail->next = new node(val);
        tail = tail->next;
    }
    cout << "Sucess " << endl;
}

//deletes the last inserted element LIFO
void linkedList :: deletion(void){
    if(head == NULL){
        cout << "There is no Linked List" << endl;
    }
    else{
        if(tail == head){
            tail = NULL;
            delete(head);
            head = NULL;
            cout << "Deleted successfully" << endl;
            cout << "Linked List Deleted successfully" << endl;
        }
        else{
            node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            delete(tail);
            tail = temp;
            tail->next = NULL;
            cout << "Deleted successfully" << endl;
        }
    }

}

// print elements of the linked list
void linkedList :: printll(void){
    node* temp = head;
    if(temp == NULL)
        cout << "There is no Linked List to Print" << endl;
    else{
        cout << "Linked List : ";
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    temp = NULL;
}

int main()
{
    char ch = 'Y';
    int value;
    linkedList ll1;
    while(ch == 'Y' || ch == 'y')
    {
        cout << "Enter a value to add in a Linked List" << endl;
        cin >>  value;
        ll1.insert(value);
        cout << endl << "Y/y to continue" << endl;
        cin >> ch;
    }
    ll1.printll();
    // int array[6] = {1,2,3,4,5,6};
    // linkedList ll2(array, sizeof(array));       // pass an array and size of it
    // ll2.printll();
    // ll2.deletion();
    // ll2.deletion();
    // ll2.deletion();
    // ll2.deletion();
    // ll2.deletion();
    // ll2.deletion();     // here all the elements are deleted and linked list gets empty
    // ll2.deletion();     // there is no element to delete
    // ll2.printll();
    return 0;
}