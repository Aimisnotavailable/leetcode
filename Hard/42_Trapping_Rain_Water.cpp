#include<vector>
#include<climits>
class Solution {
public:
    int trap(std::vector<int>& height) {
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while(l < r){
            lmax = std::max(lmax, height[l]);
            rmax = std::max(rmax, height[r]);
            res+=(lmax < rmax) ? lmax - height[l++] : rmax - height[r--];
        }

        return res;
    }
};