class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        //sort(nums.begin();nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int num :nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();

    }
};