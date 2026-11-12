class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.length();
        vector<string>words;
        stringstream ss(s);
        string token;
        int countwords=0;
        while(getline(ss,token,' ')){
            words.push_back(token);
            countwords++;
        }
        if(countwords!=n){
            return false;

        }
        unordered_map<string,char>mp;
        set<char>used;
        for(int i=0;i<n;i++){
            string word=words[i];
            char ch=pattern[i];
            if(mp.find(word)!=mp.end()){
                if(mp[word]!=ch){
                    return false;
                }
            }
            else{
                if(used.find(ch)!=used.end()){
                    return false;
                }

                mp[word]=ch;
                used.insert(ch);
            }

        }
        return true;



    }
};