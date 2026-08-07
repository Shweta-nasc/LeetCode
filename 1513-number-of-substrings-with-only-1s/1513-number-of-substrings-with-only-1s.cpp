class Solution {
public:
    int numSub(string s) {
        const int MOD=1e9+7;
        long long streak=0;
        long long ans=0;
        for(char c:s){
            if(c=='1'){
                streak++;
                ans+=streak;
            }
            else{
                streak=0;
            }
            ans=ans%MOD;
        }
        return ans;
    }
};