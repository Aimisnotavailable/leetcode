#include <vector>
#include <climits>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int max_prod = INT_MIN;
        for(int i = 0; i < n; i++){
            product *= nums[i];
            max_prod = std::max(max_prod, product);
            if(product == 0)
                product = 1;
        }
        product = 1;
        for(int i = n-1; i >= 0; i--){
            product *= nums[i];
            max_prod = std::max(max_prod, product);
            if(product == 0)
                product = 1;
        }

        return max_prod;
    }
};