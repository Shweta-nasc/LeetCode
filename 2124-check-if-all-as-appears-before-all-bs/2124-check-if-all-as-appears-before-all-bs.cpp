class Solution {
public:
    bool checkString(string s) {
        
        int n=s.length();
        bool b=false;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                b=true;

            }
            if(b){
                if(s[i]=='a'){
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};