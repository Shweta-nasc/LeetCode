class Solution {
public:
    int smallestNumber(int n, int t) {
     
     for(long long  i=n;i<INT_MAX;i++){
        long long  k=i;
       long long prod=1;
     while(k>0){
        
        long long  digit=k%10;
        prod*=digit;
        k=k/10;


     } 
     if(prod%t==0){
        return i;
     } 

     }
     return -1;
    }
};