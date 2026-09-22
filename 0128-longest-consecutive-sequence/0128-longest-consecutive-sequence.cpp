class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int count=1;
        int ans=1;
        if(n==0){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]+1){
                count++;
                ans=max(ans,count);
            }
            else if(arr[i]==arr[i-1]){
                continue;
            }
            else{
                count=1;
            }
        }
        return ans;
    }
};