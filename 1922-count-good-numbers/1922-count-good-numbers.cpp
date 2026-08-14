class Solution {
public:
    long long power(long long a,long long b,long long mod){
        
        long long ans=1;
        while(b>0){
            if(b &1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            b=b/2;

        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        const long long MOD =1e9+7;

        long long odd= n/2;
        long long even=(n+1)/2;
         //(power(5,even,MOD)*power(4,odd,MOD))%MOD;

        return (power(5,even,MOD)*power(4,odd,MOD))%MOD;


        
    }
};