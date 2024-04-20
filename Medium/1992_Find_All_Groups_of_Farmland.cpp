#include <vector>
class Solution {
public:
    std::vector<int> trav(std::vector<std::vector<int>>& land, std::vector<int> coords, int r, int c){

        if(r < 0 || r >= land.size() || c < 0 || c >= land[0].size() || land[r][c] != 1)
            return coords;

        land[r][c] = -1;

        if(r - 1 < 0 && c - 1 < 0){
            coords.push_back(r);
            coords.push_back(c);
        }else{
            if(c - 1 < 0  || r - 1 < 0){
                if(c - 1 < 0){
                    if(land[r - 1][c] == 0){
                        coords.push_back(r);
                        coords.push_back(c);
                    }
                }
                else if(r - 1 < 0){
                    if(land[r][c - 1] == 0){
                        coords.push_back(r);
                        coords.push_back(c);
                    }
                }
            }
            else if(land[r - 1][c] == 0 && land[r][c - 1] == 0){
                coords.push_back(r);
                coords.push_back(c);
            }
        }

        if(r + 1 >= land.size() && c + 1 >= land[0].size()){
            coords.push_back(r);
            coords.push_back(c);
        }else{
            if(c + 1 >= land[0].size()  || r + 1 >= land.size()){
                if(c + 1 >= land[0].size()){
                    if(land[r + 1][c] == 0){
                        coords.push_back(r);
                        coords.push_back(c);
                    }
                }
                else if(r + 1 >= land.size()){
                    if(land[r][c + 1] == 0){
                        coords.push_back(r);
                        coords.push_back(c);
                    }
                }
            }
            else if(land[r + 1][c] == 0 && land[r][c + 1] == 0){
                coords.push_back(r);
                coords.push_back(c);
            }
        }

        coords = trav(land, coords, r - 1, c);
        coords = trav(land, coords, r, c - 1);
        coords = trav(land, coords, r + 1, c);
        coords = trav(land, coords, r, c + 1);

        return coords;
    }

    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        int group_number = 2;
        std::vector<std::vector<int>> coords;
        std::vector<int> c;
        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col; j++){
                if(land[i][j] == 1){
                    c = trav(land, c, i, j);
                    if(c.size() != 0){
                        coords.push_back(c);
                        c.clear();
                    }
                };
            }
        }

        return coords;
    }
};