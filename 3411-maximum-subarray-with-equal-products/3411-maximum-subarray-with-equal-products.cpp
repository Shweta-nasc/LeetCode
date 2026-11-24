class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = std::gcd(g, (long long)nums[j]);
                l = std::lcm(l, (long long)nums[j]);

                // lcm <= 2520 and gcd <= 10, so lcm * gcd <= 25200.
                // Once prod exceeds this, no longer subarray can work.
                if (prod > 25200) break;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};