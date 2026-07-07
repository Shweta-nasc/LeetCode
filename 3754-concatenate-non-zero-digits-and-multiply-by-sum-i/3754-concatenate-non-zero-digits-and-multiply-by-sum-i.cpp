class Solution {
public:
  
    long long sumAndMultiply(int n) {
        int k;
        int ans=0;
        int newnum=0;
        int sum=0;
        while(n>0){
            k=n%10;
            if(k!=0){
                newnum=newnum*10+k;
                sum+=k;
            }
            n=n/10;
        }
        while(newnum>0){
           ans=ans*10+newnum%10;
            newnum=newnum/10;
        }
        return 1LL*ans*sum;
        
    }
};