class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int count=0;
        while(l<r){
            if(nums[l]==0&nums[r]!=0){
                swap(nums[l],nums[r]);
                r--;
                l++;
                count++;
            }
            else if(nums[l]==0&nums[r]==0){
                r--;
            }
            else if(nums[l]!=0&nums[r]==0){
                r--;
                l++;
            }
            else{
                l++;
            }
        }
        return count;
        
    }
};