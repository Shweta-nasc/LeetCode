class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=true;
        int k=10;
        


       while(n>=0){
        
            if(alice){
                if(n<k){
                    return false;
                }
                else{
                n-=k;
                k--;
                alice=false;
                }
            }
            else{
                if(n<k){
                    return true;
                }
                else{
                n-=k;
                k--;
                alice=true;
                }
            }
        
    
        
       }
       return true;
    }
};