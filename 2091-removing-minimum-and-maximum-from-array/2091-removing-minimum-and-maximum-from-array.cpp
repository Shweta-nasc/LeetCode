class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
      //  vector<int>arr=nums;
      //  sort(arr.begin(),arr.end());
        int minIN=0;
        int maxIN=0;
        int n=nums.size();
       

      for(int i=0;i<n;i++){
        if(nums[i]<nums[minIN]){
            minIN=i;
        }
        if(nums[i]>nums[maxIN]){
            maxIN=i;
        }
      }
      int left=min(minIN,maxIN);
      int right=max(minIN,maxIN);

      int front=right+1;
      int back=n-left;
      int both=left+1+n-right;
      return min(front,min(back,both));

    }
};