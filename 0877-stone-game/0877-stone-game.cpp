class Solution {
public:
    int solve(vector<int>& piles,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take_i=piles[i]+min(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
        int take_j=piles[j]+min(solve(piles,i,j-2,dp),solve(piles,i+1,j-1,dp));

        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
         int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum=accumulate(begin(piles),end(piles),0);

        int alice=solve(piles,0,n-1,dp);
        return alice>sum/2;
    }
};