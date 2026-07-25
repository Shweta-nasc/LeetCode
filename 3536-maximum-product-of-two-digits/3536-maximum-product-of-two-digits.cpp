class Solution {
public:
    int maxProduct(int n) {
        int l1=0;
        int l2=0;
        while(n>0){
            int k=n%10;
            if(k>=l1){
                l2=l1;
                l1=k;
            }
            else if(k>l2){
                l2=k;
            }
            n=n/10;

            
        }
        return l1*l2;
        
    }
};