#include <vector>
#include <algorithm>
class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int time = 0;
        for(int i = 0; i < points.size() - 1; i++){
            time+= std::max(std::abs(points[i][0] - points[i + 1][0]), std::abs(points[i][1] - points[i + 1][1]));
        }

        return time;
    }
};
