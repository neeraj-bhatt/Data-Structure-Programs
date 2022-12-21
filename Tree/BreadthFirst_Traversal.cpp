#include <iostream>
#include <queue>

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

void display_BreadthFirst(Node* root){
    queue<Node*> q;
    cout << "BreadthFirst Traversal : ";
    if(root == NULL)
        cout << "Empty";
    else{
        q.push(root);
        while(!q.empty()){
            root = q.front();
            cout << root->val << " ";
            q.pop();
            if(root->left != NULL)
                q.push(root->left);
            if(root->right != NULL)
                q.push(root->right);
        }
    }
    cout << endl;

}
int main(){
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

    display_BreadthFirst(root);
}