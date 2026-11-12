class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int icount=1;
        int dcount=1;
        int ans=1;

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                icount++;
                dcount=1;
            }
            else if(nums[i-1]>nums[i]){
                dcount++;
                icount=1;
            }
            else{
                icount=1;
                dcount=1;
             
            }
            ans=max(ans,max(dcount,icount));
        }
        return ans;
    }
};