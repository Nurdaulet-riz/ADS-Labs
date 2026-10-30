#include <iostream>
#include <string>
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
        if(x <= current->value){
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

bool check(Node* root, const string& way){
    Node* current = root;
    for(char c : way){
        if(c == 'L'){
            current = current->left;
        }
        else{
            current = current->right;
        }
        if(current == nullptr){
            return false;
        }
    }
    return true;
}

int main(){
    int n, k;
    cin >> n >> k;
    int x;
    cin >> x;
    Node* root = new Node(x);
    for(int i = 1; i < n; i++){
        cin >> x;
        insert(root, x);
    }
    string way;
    while(k--){
        cin >> way;
        if(check(root, way)){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;


}