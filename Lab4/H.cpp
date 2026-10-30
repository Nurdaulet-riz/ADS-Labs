#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int x){
        value = x;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node* root, int x){
    Node* current = root;
    while(true){
        if(x < current->value){
            if(current->left == nullptr){
                current->left = new Node(x);
                return;
            }
            current = current -> left;
        }
        else{
            if(current->right == nullptr){
                current->right = new Node(x);
                return;
            }
            current = current -> right;
        }
    }
}

void change(Node* root, int& sum){
    if(root == nullptr){
        return;
    }
    change(root->right, sum);
    sum += root->value;
    root->value = sum;
    change(root->left, sum);
}

void print(Node* root){
    if(root == nullptr){
        return;
    }
    print(root->right);
    cout << root->value << " ";
    print(root->left);
}
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    Node* root = new Node(x);
    for(int i = 1; i < n; i++){
        cin >> x;
        insert(root, x);
    }
    int ans = 0;
    change(root, ans);
    print(root);
    return 0;
}