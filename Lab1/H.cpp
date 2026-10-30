#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> age(n);
    for(int i = 0; i < n; i++){
        cin >> age[i];
    }
    stack<int> q;
    vector<int>ans(n);

    for(int i = 0; i < n; i++){
        while(!q.empty() && age[q.top()] >= age[i]){
            q.pop();
        }
        if(q.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = q.top() + 1;
        }
        q.push(i);
        
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}