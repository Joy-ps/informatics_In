#include <bits/stdc++.h>
using namespace std;
const int MAXVAL = 1000000;
int q[MAXVAL + 1];
int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int L = 0;
    int dcount = 0;
    int maxlen = 0;
    int bestl = 1, bestr = 1;
    for (int R = 0; R < n; R++) {
        if (q[a[R]] == 0) {
            dcount++;
        }
        q[a[R]]++;
        while (dcount > k) {
            q[a[L]]--;
            if (q[a[L]] == 0) {
                dcount--;
            }
            L++;
        }
        int currentl = R - L + 1;
        if (currentl > maxlen) {
            maxlen = currentl;
            bestl = L + 1; 
            bestr = R + 1;
        }
    }
    cout << bestl << " " << bestr << "\n";
    return 0;
}