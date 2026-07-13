class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        int lowlen=to_string(low).length();
        int highlen=to_string(high).length();
        for(int i=lowlen;i<=highlen;i++){
            for(int j=0;j+i<=9;j++){
                int num=stoi(s.substr(j,i));
                if(num>=low&&num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};