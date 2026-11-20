class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a memoization table to store computed results
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        // Call the recursive function to compute unique paths
        return uniquePathsRecursive(0, 0, m, n, memo);
    }
    
    int uniquePathsRecursive(int x, int y, int m, int n, vector<vector<int>>& memo) {
        // If we reach the destination (bottom-right corner), return 1
        if (x == m - 1 && y == n - 1) {
            return 1;
        }
        
        // If we have already computed the result for this cell, return it from the memo table
        if (memo[x][y] != -1) {
            return memo[x][y];
        }
        
        // Calculate the number of unique paths by moving right and down
        int rightPaths = 0;
        int downPaths = 0;
        
        // Check if it's valid to move right
        if (x < m - 1) {
            rightPaths = uniquePathsRecursive(x + 1, y, m, n, memo);
        }
        
        // Check if it's valid to move down
        if (y < n - 1) {
            downPaths = uniquePathsRecursive(x, y + 1, m, n, memo);
        }
        
        // Store the result in the memo table and return it
        memo[x][y] = rightPaths + downPaths;
        return memo[x][y];
    }
};