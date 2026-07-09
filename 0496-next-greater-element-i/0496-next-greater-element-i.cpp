class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m =nums2.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        stack<int>s;
        for(int i=m-1;i>=0;i--){
            while(!s.empty()&&nums2[i]>=s.top()){
                s.pop();
            }
             if(s.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=s.top();

            }
            s.push(nums2[i]);

        }

        for(int x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};