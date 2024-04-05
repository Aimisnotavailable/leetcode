#include<vector>
#include<algorithm>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        int arrow_count = 1;
        int left = 0;
        int right = left + 1;
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        while(right < points.size()){
            bool in_bound = true;
            if(points[left][1] < points[right][0]){
                in_bound = false;
            }
            if(!in_bound){
                left = right;
                arrow_count++;
            }
            right++;
        }
        return arrow_count;
    }
};