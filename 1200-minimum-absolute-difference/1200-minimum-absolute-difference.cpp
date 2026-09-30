class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int mindif=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
          
                mindif=min(mindif,abs(arr[i-1]-arr[i]));
            }
        
        vector<vector<int>>ans;
          for(int i=1;i<n;i++){
            
                if(abs(arr[i-1]-arr[i])==mindif){
                   ans.push_back({arr[i-1],arr[i]});
                    }
                

            }
          
          return ans;
    }
};