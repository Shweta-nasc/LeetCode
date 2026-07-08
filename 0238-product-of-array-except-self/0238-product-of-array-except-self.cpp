class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        // vector<int>ProdSuf(n,1);
       int prefix=1;
        for(int i=1;i<nums.size();i++){
            prefix*=nums[i-1];
           ans[i]=prefix;
           
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;

    }
};