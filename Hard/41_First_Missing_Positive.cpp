#include<vector>
#include<algorithm>
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int count = 1;

        for(int i = 0; i < nums.size(); i++){
            if(i + 1 < nums.size()){
                if(nums[i] == nums[i+1]){
                    continue;
                }
            }
            if(nums[i] != count && nums[i] > 0)
                return count;
            else if(nums[i] == count)
                count++;
        }
        return count;
    }
};