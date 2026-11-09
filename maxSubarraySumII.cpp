#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + x[i];
    }
    deque<int> d;
    long long maxsum = 0;
    bool firstv = true; 
    for (int i = a; i <= n; i++) {
        int add = i - a;
        while (!d.empty() && P[d.back()] >= P[add]) {
            d.pop_back();
        }
        d.push_back(add);
        while (!d.empty() && d.front() < i - b) {
            d.pop_front();
        }
        long long current_max = P[i] - P[d.front()];
        if (firstv) {
            maxsum = current_max;
            firstv = false;
        } else {
            maxsum = max(maxsum, current_max);
        }
    }
    cout << maxsum << "\n";
    return 0;
}