class Solution {
public:
    int digitsum(int x){
        int sum=0;
        while(x>0){
            int k=x%10;
            sum+=k;
            x=x/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ind=INT_MAX;
        for(int i=0;i<n;i++){
            if(digitsum(nums[i])==i){
                ind=min(ind,i);
            }
        }

        return (ind==INT_MAX)? -1:ind;
    }
};