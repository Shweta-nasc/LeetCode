class Solution {
public:
    vector<string>ans;
    void solve(int n,string curr, int o,int c){
        if(curr.size()==2*n){
            ans.push_back(curr);
        }
        if(o<n){
            solve(n,curr+"(",o+1,c);
        }
      if(c<o){
             solve(n,curr+")",o,c+1);

        }

    }
    vector<string> generateParenthesis(int n) {
        solve(n,"",0,0);
        return ans;
    }
};