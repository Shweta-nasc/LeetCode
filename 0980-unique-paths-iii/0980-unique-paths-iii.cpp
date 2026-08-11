class Solution {
public:
    int ans;
    void dfs(int i,int j,vector<vector<int>>& grid,int valid){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1){
            return ;
        }

        if(grid[i][j]==2&&valid==0){
            ans++;
        }

      int temp=grid[i][j];
      grid[i][j]=-1;

        dfs(i+1,j,grid,valid-1);
        dfs(i-1,j,grid,valid-1);
        dfs(i,j+1,grid,valid-1);
        dfs(i,j-1,grid,valid-1);


        grid[i][j]=temp;



    }

    int uniquePathsIII(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int s1,s2;
       int valid=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                s1=i;
                s2=j;
            }
            else if(grid[i][j]==0){
                valid++;
            }
        }
       }

       dfs(s1,s2,grid,valid);
       return ans;

    }
};