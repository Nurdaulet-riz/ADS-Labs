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
            current = current->left;
        }
        else{
            if(current->right == nullptr){
                current->right = new Node(x);
                return;
            }
            current = current->right;
        }
    }
}

int Check(Node* root){
    if(root == nullptr){
        return 0;
    }
    int count = 0;
    if(root->left != nullptr && root->right != nullptr){
        count = 1;
    }
    return count + Check(root->left) + Check(root->right);
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
    cout << Check(root);
    return 0;
}