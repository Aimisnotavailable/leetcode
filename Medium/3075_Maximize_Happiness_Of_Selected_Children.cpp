#include<vector>
#include<algorithm>
#include<functional>
class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        int count = 0;
        long long int sum = 0;
        std::sort(happiness.begin(), happiness.end(), std::greater<int>());
        
        for(int i = 0; i < k; i++){
            sum+=std::max(0, happiness[i] - count++);
        }
        return sum;
    }
};
