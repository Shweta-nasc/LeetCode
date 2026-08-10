class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldcolor,int color){

        if(i<0||i>=image.size()||j<0||j>=image[0].size()){
            return ;
        }
        if(image[i][j]!=oldcolor){
            return ;
        }
        image[i][j]=color;


       dfs(image,i+1,j,oldcolor,color);
        dfs(image,i,j+1,oldcolor,color);
        dfs(image,i,j-1,oldcolor,color);
          dfs(image,i-1,j,oldcolor,color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldcolor=image[sr][sc];
        if(oldcolor==color){
            return image;
        }

        dfs(image,sr,sc,oldcolor,color);

        return image;
        
    }
};