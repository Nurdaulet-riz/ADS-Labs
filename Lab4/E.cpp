#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> left(n + 1, -1);
    vector<int> right(n + 1, -1);
    int p, c, side;
    for(int i = 0; i < n - 1; i++){
        cin >> p >> c >> side;
        if(side == 0){
            left[p] = c;
        }
        else{
            right[p] = c;
        }
    }

    queue<int> q;
    q.push(1);
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        ans = max(ans, size);
        for(int i = 0; i < size; i++){
            int v = q.front();
            q.pop();
            if(left[v] != -1){
                q.push(left[v]);
            }
            if(right[v] != -1){
                q.push(right[v]);
            }
        }
    }
    cout << ans;
    return 0;
}