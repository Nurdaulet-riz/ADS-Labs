#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int First(const vector<long long>& a, long long x){
    long long left = 0;
    long long right = a.size();
    while(left < right){
        long long mid = left + (right - left) / 2;
        if(a[mid] >= x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}
int Second(const vector<long long>& a, long long x){
    long long left = 0;
    long long right = a.size();
    while(left < right){
        long long mid = left + (right - left) / 2;
        if(a[mid] > x){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}
int count(const vector<long long>& a, long long l, long long r){
    return Second(a, r) - First(a, l);
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long l1, r1, l2, r2;
    while(q--){
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        int ans;
        if(r1 < l2){
            ans = count(a, l1, r1) + count(a, l2, r2);
        }
        else{
            ans = count(a, l1, max(r1, r2));
        }
        cout << ans << '\n';
    }
    return 0;

}