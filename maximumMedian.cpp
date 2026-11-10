#include <bits/stdc++.h>
using namespace std;
int t(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int start_index = arr.size() / 2;
    for (int i = 0; i < k; ++i) {
        sort(arr.begin() + start_index, arr.end());
        arr[start_index] += 1;
    }
    sort(arr.begin() + start_index, arr.end());
    return arr[start_index];
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = t(a, k);
    cout  << ans << endl;
    return 0;
}