#include <iostream>
#include <vector>
#include <queue>
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
            if(current->left == nullptr){
                current->left = new Node(x);
                return;
            }
            current = current->right;
        }
    }
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
    queue<Node*> q;
    q.push(root);
    vector<int> sums;
    while(!q.empty()){
        int sum = 0;
        for(int i = 0; i < q.size(); i++){
            Node* current = q.front();
            q.pop();
            sum += current->value;
            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
        sums.push_back(sum);
    }
    cout << sums.size() << '\n';
    for(int x : sums){
        cout << x << " ";
    }
    return 0;
}