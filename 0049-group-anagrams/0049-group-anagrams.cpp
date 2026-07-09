class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
       // int n=strs.size();
        for(string s:strs){
            string k=s;
            sort(k.begin(),k.end());
            mp[k].push_back(s);
            
        }
        vector<vector<string>>ans;
        for(auto &P:mp){
            ans.push_back(P.second);
        }
        return ans;
    }
};