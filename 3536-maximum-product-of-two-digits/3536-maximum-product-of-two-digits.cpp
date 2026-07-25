class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;

        while(n>0){
            int k=n%10;
            arr.push_back(k);
            n=n/10;
        }
        sort(arr.begin(),arr.end());
        int p=arr.size();
        return arr[p-1]*arr[p-2];
    }
};