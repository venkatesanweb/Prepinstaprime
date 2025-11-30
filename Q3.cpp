#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    if (k == 0) {
        int ORall = 0;
        for (int x : nums) ORall |= x;
        cout << ORall;
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n - (k+1); i++) {
        int blockAND = nums[i];
        for (int j = i+1; j <= i+k; j++)
            blockAND &= nums[j];

        int ORvalue = blockAND;
        for (int t = 0; t < n; t++) {
            if (t < i || t > i+k)
                ORvalue |= nums[t];
        }

        ans = min(ans, ORvalue);
    }

    cout << ans;
    return 0;
}

