class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int &n:nums){
            n=abs(n);
        }
        sort(nums.begin(),nums.end());
       // vector<int>large;
       // vector<int>small;

       long long ans=0;
       
        for(int i=0;i<n;i++){
            long long x=nums[i];
            if(i<n/2){
                ans-=x*x;
            }
            else{
                ans+=x*x;
            }
           
        }
        return ans;

    }
};