#include<vector>

class Solution {
public:
    void trav(std::vector<std::vector<char>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1')
            return;
        grid[r][c] = '2';
        trav(grid, r + 1, c);
        trav(grid, r - 1, c);
        trav(grid, r, c + 1);
        trav(grid, r, c - 1);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    trav(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};