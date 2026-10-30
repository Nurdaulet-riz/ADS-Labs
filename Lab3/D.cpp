#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS(const vector<long long>& a, long long x){
    int left = 0;
    int right = a.size();
    while(left < right){
        int mid = left + (right - left) / 2;
        if(a[mid] > x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + a[i];
    }
    int m;
    cin >> m;
    while(m--){
        long long x;
        cin >> x;
        int cnt = BS(a, x);
        cout << cnt  << " " << prefix[cnt] << '\n';
    }
    return 0;
}