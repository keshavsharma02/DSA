class Solution {
public:
bool solve(vector<vector<char>>&grid,int row,int col,int i,int j,vector<vector<int>>&visited,char c,vector<int>&dx,vector<int>&dy,int count,int parentX,int parentY){
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int newX=i+dx[k];
        int newY=j+dy[k];
        if(newX>=0 && newX<row && newY>=0 && newY<col){
            if(grid[newX][newY]==c){
                if(visited[newX][newY]==0){
                   if(solve(grid,row,col,newX,newY,visited,c,dx,dy,count+1,i,j)){
                    return true;
                   }
                }
                else if(visited[newX][newY]==1 && count>2 && (newX!=parentX || newY!=parentY)){
                    return true;
                }
            }
        }
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>dx={1,0,-1,0};
        vector<int>dy={0,-1,0,1};
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char c=grid[i][j];
                int count=0;
                if(visited[i][j]==0){
                if(solve(grid,row,col,i,j,visited,c,dx,dy,count,-1,-1)){
                    return true;
                }
                }
            }
        }
        return false;
    }
};