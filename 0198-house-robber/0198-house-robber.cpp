class Solution {
public:

int solve(int i, vector<int>&nums,vector<int>&dp){
          if(i<0)return 0 ;
        if(dp[i]!=-1){
            return dp[i];
        }
          int rob=nums[i]+solve(i-2,nums,dp);
          int skip=solve(i-1,nums,dp);

          return dp[i]=max(rob,skip);
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
    return solve(n-1,nums,dp);

    }
};







  /*  int n=nums.size();
        if(n==1)return nums[0];
        int prev1=nums[0];
        int prev2=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(nums[i]+prev1,prev2);
            prev1=prev2;
            prev2=curr;
        }
        return prev2;*/