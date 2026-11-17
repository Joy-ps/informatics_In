#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (a[j] - a[i] <= k) {
                count++;
            } else {
                break; 
            }
        }
        ans = max(ans, count);
    }
    cout << ans << "\n";
    return 0;
}