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

class linkedList{
    node* head;
    node* tail;
    public:
    linkedList(){       //default constructor
        head = NULL;
        tail = NULL;
    }  
    linkedList(int* arr, int arraysize);    //constructor for an array
    ~linkedList();  //destructor
    void insert_frnt(int val);
    void insert_rear(int val);
    void del_frnt();
    void del_rear();
    void reverse_linkedlist();
    void print_linkedlist(); 

};

//destructor
linkedList :: ~linkedList(){
    node* des = NULL;
    tail = NULL;
    while(head != NULL){
        des = head;
        head = head->next;
        delete(des);
    }
}

//array into linked list
linkedList :: linkedList(int* arr, int arraysize){
    if(arr == NULL)
        return;

    int array_elements = arraysize/sizeof(int);
    int count = 1;
    head = new node(arr[0]);
    tail = head;
    if(array_elements>1){
        while(count<array_elements){
            tail->next = new node(arr[count]);
            tail = tail->next;
            count++;
        }
    }
}

//print elements of linked list
void linkedList :: print_linkedlist(){
    node* ptr = head;
    if(head == NULL)
        cout << "There in no Linked List to print" << endl;
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

void linkedList :: reverse_linkedlist(){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* prevnode = NULL;
    node* current = head;
    node* nextnode = NULL;
    while(current != NULL){
        nextnode = current->next;   //stores the next pointer
        current->next = prevnode;   //reverse node
        
        prevnode = current;     //one step
        current = nextnode;     //increases
    }
    //update head and tail pointers
    tail = head;
    head = prevnode;
    prevnode = NULL;
}

// deletion of an element from head
// head is moved accordingly
void linkedList :: del_frnt(){
    node* temp = NULL;
    if(head == NULL)
        cout << "Linked List is empty" << endl;
    else{
        temp = head;
        if(head == tail)
            tail = NULL;
        head = head->next;
        cout << "Deleted Successfully : " << temp->val << endl;
        delete(temp);
    }
}

// deletion of an element from rear
// tail is moved accordingly
void linkedList :: del_rear(){
    node* temp = NULL;
    if(head == NULL)
        cout << "Linked List is empty" << endl;
    else{
        if(head == tail){
            head = NULL;
            delete(tail);
        }
        else{
            temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            cout << "Deleted Successfully : " << tail->val << endl;
            delete(tail);
            tail = temp;
            }
    }
}

//inserts an element in the beginning of a linked list
void linkedList :: insert_frnt(int val){
    if(head == NULL){
        tail = new node(val);
        head = tail;
    }
    else{
        node* temp = new node(val);
        temp->next = head;
        head = temp;
    }
}

//inserts an element at the end of a linked list
void linkedList :: insert_rear(int val){
    if(head == NULL){
        head = new node(val);
        tail = head;
    }
    else{
        tail->next = new node(val);
        tail = tail->next;
    }
}

int main()
{
    linkedList ll1;
    ll1.insert_frnt(5);
    ll1.insert_frnt(6);
    ll1.insert_rear(8);
    ll1.insert_frnt(9);
    ll1.print_linkedlist();
    // ll1.del_frnt();
    // ll1.print_linkedlist();
    // ll1.del_rear();
    // ll1.print_linkedlist();
    ll1.reverse_linkedlist();
    ll1.print_linkedlist();

    int arr[6] = {1,2,3,4,5,6};
    linkedList ll2(arr, sizeof(arr));
    ll2.print_linkedlist();

    return 0;
}