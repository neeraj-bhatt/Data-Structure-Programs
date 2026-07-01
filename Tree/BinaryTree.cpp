#include <iostream>
#include <queue>
using namespace std;

struct Node{
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

class BinaryTree{
    Node* root;
    void inOrder(Node* node){
        if(node == NULL)
            return;

        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node){
        if(node == NULL)
            return;
        
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node){
        if(node == NULL)
            return;
        
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }

    void levelOrder(Node* node){
        if(node == NULL)
            return;
        
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }

    void destroy(Node* node){
        if(node == NULL)
            return;
        
        destroy(node->left);
        destroy(node->right);

        delete node;
    }

    public:

    BinaryTree(){
        root = NULL;
    }

    ~BinaryTree(){
        destroy(root);
    }

    // insert an element in the binary tree
    void insert(int v){
        if(root == NULL){
            root = new Node(v);
        }
        else{
            Node* temp = root;
            while(true){
                if(v > temp->val){
                    if(temp->right == NULL)
                        break;
                    temp = temp->right;
                }
                else{
                    if(temp->left == NULL)
                        break;
                    temp = temp->left;
                }
            }
            if(v > temp->val)
                temp->right = new Node(v);
            else
                temp->left = new Node(v);
        }
    }

    void deleteNode(int v){

        
    }

    // check the presence of an element
    bool search(int v){
        if(!root) return false;
        Node* temp = root;
        while(true){
            if(v == temp->val)
                return true;
            else{
                if(v > temp->val){
                    if(temp->right == NULL)
                        return false;
                    temp = temp->right;
                }else{
                    if(temp->left == NULL)
                        return false;
                    temp = temp->left;
                }
            }
        }
    }

    // displays elements in different orders
    void display(string order = "inorder"){
        if(order == "inorder")
            inOrder(root);
        else if(order == "preorder")
            preOrder(root);
        else if(order == "postorder")
            postOrder(root);
        else if(order == "levelorder")
            levelOrder(root);
        else
            inOrder(root);
    }

    // returns node with minimum value in Binary Tree
    Node* minNode(){
        Node* temp = root;
        while(temp->left)
            temp = temp->left;

        return temp;
    }

    // returns node with maximaum value in Binary Tree
    Node* maxNode(){
        Node* temp = root;
        while(temp->right)
            temp = temp->right;
        
        return temp;
    }

};

int main() {

    // Test case generated with the help of ChatGPT
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.display("inorder");
    cout << endl;

    cout << "Preorder: ";
    tree.display("preorder");
    cout << endl;

    cout << "Postorder: ";
    tree.display("postorder");
    cout << endl;

    cout << "Levelorder: ";
    tree.display("levelorder");
    cout << endl;

    cout << "\nSearch 40: ";
    cout << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "Search 100: ";
    cout << (tree.search(100) ? "Found" : "Not Found") << endl;

    cout << "\nMinimum Node: " << tree.minNode()->val << endl;
    cout << "Maximum Node: " << tree.maxNode()->val << endl;

    return 0;
}