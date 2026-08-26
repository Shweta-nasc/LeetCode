class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>mp;
        for(int x:nums){
            mp.insert(x);
        }
        int n=nums.size();
        for(int i=1;i<=n+1;i++){
            if(mp.find(k*i)==mp.end()){
                return k*i;
            }
        }
        return -1;
    }
};