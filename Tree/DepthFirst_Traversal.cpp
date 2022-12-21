#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(){}
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

void inorder_Display(Node* root){   //Inorder Traversal
    if(root != NULL){
        inorder_Display(root->left);
        cout << root->val << " ";
        inorder_Display(root->right);
    }
}
void preorder_Display(Node* root){  //Preorder Traversal
    if(root != NULL){
        cout << root->val << " ";
        preorder_Display(root->left);
        preorder_Display(root->right);
    }
}
void postorder_Display(Node* root){  //Postorder Traversal
    if(root != NULL){
        postorder_Display(root->left);
        postorder_Display(root->right);
        cout << root->val << " ";
    }
}

int main() {

    /*
                        10
                       /  \
                     5     20
                   /  \   /  \
                  2   8  15   25
    
     */
    //above tree as a example through hard coding
    Node* root = new Node(10);
    Node* p = new Node(5);
    Node* q = new Node(20);
    root->left = p;
    root->right = q;
    p->left = new Node(2);
    p->right = new Node(8);
    q->left = new Node(15);
    q->right = new Node(25);
    cout << "Inorder Traversal : ";
    inorder_Display(root);
    cout << endl;
    cout << "Preorder Traversal : ";
    preorder_Display(root);
    cout << endl;
    cout << "Postorder Traversal : "; 
    postorder_Display(root);
    cout << endl;

    return 0;
}