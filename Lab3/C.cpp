#include <iostream>
#include <vector>
using namespace std;

int BS(const vector<long long>& a, long long x){
    int left = 0;
    int right = a.size() - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(a[mid] >= x){
           right = mid; 
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    cin >> a[0];
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    while(m--){
        int mistake;
        cin >> mistake;
        int ans = BS(a, mistake);
        cout << ans + 1 << '\n';
    }
    return 0;
}