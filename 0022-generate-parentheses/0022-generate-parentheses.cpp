class Solution {
public:
    void solve(int n,int left,int right ,vector<string>&ans,string s){
        if(s.length()==2*n){
            ans.push_back(s);
        }
        if(left<n){
            solve(n,left+1,right,ans,s+'(');
        }
        if(right<left){
            solve(n,left,right+1,ans,s+')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,0,ans,"");
        return ans;
    }
};