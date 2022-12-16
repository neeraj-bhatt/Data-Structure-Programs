#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node();
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
class BinarySearchTree{
    public:
    int data;
    Node* root;
    BinarySearchTree(){
        root = NULL;
    }
    void insertion();
    void search();
};

void BinarySearchTree :: search(){
    Node* p;
	int data;
    bool flag = false;
    cout << "Enter value to search : ";
    cin >> data;
    if(data == root->val){
        cout << "Value found at root" << endl;
    }
    else{
        p = root;
        while(true){
            if(data > p->val){
                if(p->right == NULL){
                    flag = true;
                    break;
                }
                p = p->right;
            }
            else if(data < p->val){
                if(p->left == NULL){
                    flag = true;
                    break;
                }
                p = p->left;
            }
            else{
                cout << "Value found" << endl;
            }
        }
        if(flag)
            cout << "Value not found" << endl;
    }
}

void BinarySearchTree :: insertion(){
    Node* p;
    int value;
    cout << "Value : ";
    cin >> value;
    if(root == NULL)
        root = new Node(value);
    else{
        p = root;
        while(true){
            if(value > p->val){
                if(p->right == NULL)
                    break;
                p = p->right;
            }
            else{
                if(p->left == NULL)
                    break;
                p = p->left;
            }
        }
        if(value > p->val)
            p->right = new Node(value);
        else
            p->left = new Node(value);
    }
}
void display(Node* root){
    if(root != NULL){
        display(root->left);
        display(root->right);
        cout << root->val << " ";
    }
}
void mirror_image(Node* root){
    if(root!=NULL){
        if(root->left){
            mirror_image(root->left);
        }
        if(root->right){
            mirror_image(root->right);
        }
        Node* ptr=root->right;
        root->right=root->left;
        root->left=ptr;
        return ;
    }
    return ;
}


int main() {
    BinarySearchTree obj;
    int choice;
	while(1){
		cout << "\n1.Insertion\n2.Mirror\n3.Display\n4.Search\n5.Exit\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.insertion();
            break;
        case 2:
            mirror_image(obj.root);
            break;
        case 3:
            display(obj.root);
            break;
        case 4:
            obj.search();
            break;
        case 5:
            exit(0);
        default:
            cout << " Wrong choice";
            break;
        }
	}

    return 0;
}
