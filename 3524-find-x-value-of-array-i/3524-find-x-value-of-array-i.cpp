class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> next(k, 0);

            // Start a new subarray with x
            next[x % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int nr = (r * (x % k)) % k;
                next[nr] += dp[r];
            }

            // Add all subarrays ending at x
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};