class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
         int minLen=INT_MAX;
        int sum=0;

        while(r<n){
           
            sum+=nums[r];
            
           while(sum>=target){
                minLen=min(minLen,r-l+1);
                sum-=nums[l];
                l++;
        }
        r++;
        }
        
        return (minLen==INT_MAX)?0:minLen;
    }
};



//brute force
        /*
        int n=nums.size();
        int minLen=INT_MAX;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    minLen=min(minLen,j-i+1);
                }

            }
        }
        return (minLen==INT_MAX)? 0:minLen;*/