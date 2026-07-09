class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
             unordered_map<int,int> mp;
        long long ans = 0;

        for (int x : nums) {
            int g = gcd(x, k);

            for (auto &[d, cnt] : mp) {
                if (1LL * g * d % k == 0)
                    ans += cnt;
            }

            mp[g]++;
        }

        return ans;
    }
};