#include <iostream>
#include <vector>
using namespace std;

int BS(const vector<long long>& pref, int l, int n, long long k){
    int left = l;
    int right = n - 1;
    int ans = n;
    while(left <= right){
        int mid = left + (right - left) / 2;
        long long sum = pref[mid + 1] - pref[l];
        if(sum >= k){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> pref(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = n;
    for(int l = 0; l < n; l++){
        int r = BS(pref, l, n, k);
        if(r != n){
            ans = min(ans, r - l + 1);
        }
    }
    cout << ans;
    return 0;
}