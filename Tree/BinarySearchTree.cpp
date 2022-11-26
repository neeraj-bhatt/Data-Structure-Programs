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

void display(Node* root){
    if(root != NULL){
        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
}
int main() {
    Node* root = NULL;
    Node* p = NULL;
    char ch = 'Y';
    int value;
    while(ch == 'y' || ch == 'Y'){
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
        cout << "Y to continue : ";
        cin >> ch;
    }
    display(root);

    return 0;
}