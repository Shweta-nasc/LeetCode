class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left=0;
        int right=0;
        int n=s.length();
        int m=t.length();
        while(right<m){
            if(s[left]==t[right]){
                left++;
                right++;
                
            }
            else{
            right++;}
        }

        if(left>=n){
            return true;
        }
        return false;
    }
};