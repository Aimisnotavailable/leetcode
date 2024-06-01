#include<vector>
#include<climits>
#include<algorithm>
class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), i = 0, j = 0;
        std::vector<std::vector<int>> ans;
        while(i + 3 <= n ){
            std::vector<int> temp;
            ans.push_back(temp);
            while(j + 3 <= n){
                int lmax = INT_MIN;
                for(int r = i; r < i + 3; r++){
                    for(int c = j; c < j + 3; c++){
                        lmax = std::max(lmax, grid[r][c]);
                    }
                }
                ans[i].push_back(lmax);
                j++;
            }
            j = 0;
            i++;
        }
        return ans;
            
    }
};
