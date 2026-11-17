#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<pair<ll, ll>> intervals;
bool d(ll d) {
    ll cowsPlaced = 1;
    ll lastPos = intervals[0].first;
    int i = 0;
    while (cowsPlaced < n) {
        ll nextMinPos = lastPos + d;
        while (i < m && intervals[i].second < nextMinPos) {
            i++;
        }
        if (i == m) return false;
        lastPos = max(intervals[i].first, nextMinPos);
        cowsPlaced++;
    }
    return true;
}
int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    intervals.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    ll lo = 1, hi = 1e18;
    ll ans = 1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (d(mid)) {
            ans = mid;      
            lo = mid + 1;
        } else {
            hi = mid - 1;   
        }
    }
    cout << ans << "\n";
    return 0;
}