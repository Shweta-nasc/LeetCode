class Solution {
public:
    string processing(string s){
        string ans="";
        int cnt=1;
     for(int i=1;i<=s.length();i++){
      if(i<s.length()&&s[i]==s[i-1]){
        cnt++;
      }
      else{
        ans+=to_string(cnt);
        ans+=s[i-1];
        cnt=1;
      }
     }

     return ans;
        
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        return processing(countAndSay(n-1));
    }
};