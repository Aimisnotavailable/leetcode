#include <vector>
class Solution {
private:
    int trav(std::vector<std::vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 1;
        if(grid[r][c] == -1)
            return 0;

        grid[r][c] = -1;

        return (trav(grid, r - 1, c) +
                trav(grid, r + 1, c) +
                trav(grid, r, c-1) +
                trav(grid, r, c + 1));

    }
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1)
                    perimeter += trav(grid, i, j);
            }
        }

        return perimeter;
    }
};