#include<vector>
class Solution {
public:
    
    int trav(std::vector<std::vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return 0;
        
        int max_gold = 0;
        int val = grid[row][col];
        
        grid[row][col] = 0;
        
        max_gold = max(max_gold, trav(grid, row + 1, col));
        max_gold = max(max_gold, trav(grid, row - 1, col));
        max_gold = max(max_gold, trav(grid, row, col + 1));
        max_gold = max(max_gold, trav(grid, row, col - 1));
        
        grid[row][col] = val;
        return max_gold + val;
    }
    
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        
        int max_gold = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                max_gold = max(max_gold, trav(grid, i, j));
            }
        }
        
        return max_gold;
    }
};
