class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
            return 1;
        }
        if(grid[i][j]==0){
            return 1;
        }
        if(grid[i][j]==-1){
            return 0;
        }
        grid[i][j]=-1;
       
        return dfs(grid,i+1,j) + dfs(grid,i,j-1)+dfs(grid,i-1,j)+dfs(grid,i,j+1);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return  dfs(grid,i,j);
                    
                }
            }
        }






        return 0;

    }
};