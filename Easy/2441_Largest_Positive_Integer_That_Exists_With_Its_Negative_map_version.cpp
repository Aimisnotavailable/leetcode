class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::unordered_map<int, int> a; 
        std::sort(nums.begin(), nums.end());
        int j = nums.size() - 1;
        int i = 0;

        while(j > 0 && nums[j] > 0 ){
            a[nums[j--]] = -1;
        }
        std::cout << "HEHE";
        while( i < nums.size() && nums[i] < 0){
            int curr = std::abs(nums[i++]);
            if(a.find(curr) != a.end())
                return curr;
        }

        return -1;
    }
};
