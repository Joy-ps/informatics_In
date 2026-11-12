#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool h(const string& s, int left, int right, int k) {
        if (left >= right) {
            return true;
        }
        if (s[left] == s[right]) {
            return h(s, left + 1, right - 1, k);
        }
        if (k == 0) {
            return false;
        }
        return h(s, left + 1, right, k - 1) || h(s, left, right - 1, k - 1);
    }
public:
    bool validPalindrome(string s) {
        return h(s, 0, s.length() - 1, 1);
    }
};