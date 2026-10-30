#include <iostream>
#include <algorithm>
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
        if(x == current->value){
            return;
        }

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
int height(Node* root, int& ans){
    if(root == nullptr){
        return 0;
    }
    int left = height(root->left, ans);
    int right = height(root->right, ans);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
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
    int ans = 1;
    height(root, ans);
    cout << ans;
    return 0;
}