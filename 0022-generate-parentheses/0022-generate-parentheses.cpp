class Solution {
public:
    void solve(int n,int left,int right,string curr,vector<string>&ans){
        if(curr.length()==2*n){
            ans.push_back(curr);
        }if(left<n){
        solve(n,left+1,right,curr+'(',ans);
        }
        if(left>right){
            solve(n,left,right+1,curr+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};