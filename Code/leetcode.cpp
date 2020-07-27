#include<bits/stdc++.h>
using namespace std;
const int MAX = 1123;
    int minPathSum(vector<vector<int>>& grid) {
        int dp[MAX][MAX];
        int m = grid.size();
        int n = grid[0].size();
        /*cout <<  m << " " << n << endl;*/
        /*dp[0][0] = grid[0][0];*/
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int j = 1; j < n; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }

[1, 2, 5]
dp[0] = 0;
dp[1] = 0 + 0;
int main()
{
    vector<vector<int>> matrix;
    int ans;
    matrix = {{1,2,5},{3,2,1}};
    cout << minPathSum(matrix) << endl;
}