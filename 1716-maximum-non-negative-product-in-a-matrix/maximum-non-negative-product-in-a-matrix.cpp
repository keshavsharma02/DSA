class Solution {
public:
    pair<long long,long long> dp[16][16];
    bool vis[16][16];
    const long long MOD = 1e9 + 7;

    pair<long long,long long> solve(int i,int j,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
      
        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }
      
        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        long long maxi_p = LLONG_MIN;
        long long mini_p = LLONG_MAX;

        if(j+1<m){
            auto res = solve(i,j+1,grid);
            long long first = grid[i][j] * res.first;
            long long second = grid[i][j] * res.second;
            maxi_p = max({maxi_p,first,second});
            mini_p = min({mini_p,first,second});
        }
        if(i+1<n){
            auto res = solve(i+1,j,grid);
            long long first = grid[i][j] * res.first;
            long long second = grid[i][j] * res.second;
            maxi_p = max({maxi_p,first,second});
            mini_p = min({mini_p,first,second});
        }
        return dp[i][j] = {mini_p,maxi_p};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));

        auto res = solve(0, 0, grid);
        if (res.second < 0) return -1;
        return res.second % MOD;
    }
};