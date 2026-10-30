#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int First(const vector<long long>& a, long long x){
    int left = 0;
    int right = a.size();
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

int Second(const vector<long long>& a, long long x){
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
int cnt(const vector<long long>& a, long long l, long long r){
    return Second(a, r) - First(a, l);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(m--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        int ans;
        if(r1 < l2){
            ans = cnt(a, l1, r1) + cnt(a, l2, r2);
        }
        else{
            ans = cnt(a, l1, max(r1, r2));
        }
        cout << ans << '\n';
    }
    return 0;

}