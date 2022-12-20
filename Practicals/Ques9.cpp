// Create and perform different operations on Double-ended Queues using Linked List implementation.

#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T info;
    node *next;

    node(T a, node *p = 0)
    {
        info = a;
        next = p;
    }

    ~node()
    {
        delete next;
    }
};

template <class T>
class queue
{
    node<T> *f;
    node<T> *r;

public:
    queue()
    {
        f = r = 0;
    }
    ~queue()
    {
        delete f;
        delete r;
    }

    void Enqueue(T ele);
    T DeQueue();
    void display();
};

template <class T>
void queue<T>::Enqueue(T ele)
{
    if (f == 0 && r == 0)
    {
        r = new node<T>(ele);
        f = r;
    }
    else
    {
        r->next = new node<T>(ele);
        r = r->next;
    }
}

template <class T>
T queue<T>::DeQueue()
{
    if (f == 0 && r == 0)
    {
        cout << "\nEmpty Stack\n";
        return -99999;
    }
    else
    {
        node<T> *tmp = f;
        f = f->next;
        T d = tmp->info;
        delete tmp;
        return d;
    }
}

template <class T>
void queue<T>::display()
{
    if (f == 0 && r == 0)
    {
        cout << "\nEmpty Stack\n";
    }
    else
    {
        for (node<T> *p = f; p != 0; p = p->next)
            cout << p->info << "\n";
    }
}

int main()
{
    int ch, n;
    queue<int> q;

    do
    {
        cout << "\nQueue Using Linked List\n\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\nEnter Your Choice=";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter a Number to be Enqueued=";
            cin >> n;
            q.Enqueue(n);
            break;

        case 2:
            n = q.DeQueue();
            if (n != -99999)
                cout << "\nElement Removed=" << n;
            break;

        case 3:
            cout << "\nElements in the Queue are:-\n";
            q.display();
            break;

        case 4:
            break;

        default:
            cout << "\nInvalid Input.\n";
        }
    } while (ch != 4);

    return 0;
}