class Solution {
public:
    bool check(vector<int>&nums,int k,int target){

        vector<int>arr=nums;
        int n=arr.size();
        int op=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]!=target){
                op++;
                arr[i]*=-1;
                arr[i+1]*=-1;

            }
        }
        return arr[n-1]==target && op<=k;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        
    return check(nums,k,1)||check(nums,k,-1);
    }
};