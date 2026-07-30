class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<int>mp;
        int ans=0;
        for(char c:word){
            mp.insert(c);
        }
        int k=mp.size();
        if(k<=8){
            ans=k;
        }
        else if(k>8&&k<=16){
             ans=8+(k-8)*2;
          //  return ans;
        }
        else if(k>16&&k<=24){
             ans=8+16+(k-16)*3;
            //return ans;
        }
        else{
             ans=8+16+24+(k-24)*4;
            //return ans;
        }
        return ans;

    }
};