#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        deque<int> pos;
        for(int i = 1; i <= n; i++){
            pos.push_back(i);
        }
        vector<int> ans(n);

        for(int card = 1; card <= n; card++){
            int moves = card;
            int size = pos.size();
            moves %= size;

            while(moves--){
                pos.push_back(pos.front());
                pos.pop_front();
            }
            ans[pos.front() - 1] = card;
            pos.pop_front();
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}