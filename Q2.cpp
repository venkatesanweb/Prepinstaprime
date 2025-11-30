#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) 
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && abs(nums[j] - nums[i]) <= min(nums[i], nums[j])) {
            ans = max(ans, nums[i] ^ nums[j]);
            j++;
        }
        if (j == i) j++;
    }

    cout << ans;
}

