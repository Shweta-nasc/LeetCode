class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int a=p.length();
        int b=s.length();
        if(a>b) return {};
        vector<int>freq1(26,0);
         vector<int>freq2(26,0);
         for(char c:p){
            freq1[c-'a']++;
         }
         for(int i=0;i<a;i++){
            freq2[s[i]-'a']++;

         }
         vector<int>ans;
         if(freq1==freq2){
            ans.push_back(0);
         }
         for(int i=a;i<b;i++){
            freq2[s[i]-'a']++;
            freq2[s[i-a]-'a']--;
            if(freq1==freq2){
                ans.push_back(i-a+1);
            }
         }
         return ans;
    }
};