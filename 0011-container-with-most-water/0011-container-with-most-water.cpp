class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=INT_MIN;
        int l=0;
        int r=n-1;
        while(l<r){
                 int newa=(r-l)*min(height[l],height[r]);
                area=max(area,newa);

            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
           
            
        }
        
        return area;
    }
};