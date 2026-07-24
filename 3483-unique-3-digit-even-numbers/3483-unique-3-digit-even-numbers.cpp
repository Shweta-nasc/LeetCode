class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        int ans=0;
        for(int digit:digits){
            freq[digit]++;
        }
        for(int i=100;i<=998;i+=2){
            vector<int>need(10,0);
            int num=i;
            need[num%10]++;
            num=num/10;
            need[num%10]++;
            num=num/10;
            need[num%10]++;
            bool ok= true;
            for(int j=0;j<10;j++){
                if(need[j]>freq[j]){
                    ok=false;
                }


            }
            if(ok)ans++;
        }
        return ans;
    }
};