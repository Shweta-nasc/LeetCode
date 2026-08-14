class Solution {
public:
    int solve(vector<int>& nums,int l,int r,vector<vector<int>>&dp ){
        if(l==r){
            return nums[l];
        }
       if(dp[l][r]!=-1){
        return dp[l][r];
       }
       int leftake=nums[l]-solve(nums,l+1,r,dp);
       int righttake=nums[r]-solve(nums,l,r-1,dp);

       return dp[l][r]=max(leftake,righttake);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        //greedily kaam krna hai 
        //end goal to win
        //player one  choose max of nums[0]and nums[n-1];
        //new array will have one no. less ,,,now player 2 will choose in between nums[1],nums[n-1],,or nums[0]and nums[n-2];
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,0,n-1,dp)>=0;
        
    }
};