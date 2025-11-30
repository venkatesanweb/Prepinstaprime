#include <bits/stdc++.h>
using namespace std;


vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> sa(n), rank(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);

    for (int i = 0; i < n; i++) rank[i] = s[i];

    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);

        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rank = tmp;
        if (rank[sa[n - 1]] == n - 1) break;
    }
    return sa;
}


vector<int> buildLCP(const string &s, const vector<int> &sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n - 1);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
        lcp[rank[i] - 1] = h;
        if (h > 0) h--;
    }
    return lcp;
}

int main() {
    string s;
    cin >> s;

    if (s.size() < 2) {
        cout << "";
        return 0;
    }

    vector<int> sa = buildSuffixArray(s);
    vector<int> lcp = buildLCP(s, sa);

    int maxLen = 0, idx = 0;
    for (int i = 0; i < lcp.size(); i++) {
        if (lcp[i] > maxLen) {
            maxLen = lcp[i];
            idx = sa[i];
        }
    }

    if (maxLen == 0) cout << "";
    else cout << s.substr(idx, maxLen);

    return 0;
}

