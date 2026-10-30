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
Node* find(Node* root, int x){
    Node* current = root;
    while(current != nullptr){
        if(x == current->value){
            return current;
        }
        if(x < current->value){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return nullptr;
}
int size(Node* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
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
    int k;
    cin >> k;
    cout << size(find(root, k));
}