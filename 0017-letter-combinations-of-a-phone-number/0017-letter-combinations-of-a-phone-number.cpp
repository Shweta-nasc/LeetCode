class Solution {
public:
vector<vector<string>>ans;
    void solve(int idx,string&digits,string&temp,vector<string>&ans,vector<string>&mapping){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters = mapping[digits[idx]-'0'];
        for(char ch:letters){
            temp.push_back(ch);
            solve(idx+1,digits,temp,ans,mapping);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>ans;
        string temp="";
        vector<string>mapping={
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        solve(0,digits,temp,ans,mapping);

            
        return ans;
    }
};