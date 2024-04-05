#include<set>
#include<vector>
#include<unordered_map>
#include<climits>

class Solution {
public:
    std::vector<long long> mostFrequentIDs(std::vector<int>& nums, std::vector<int>& freq) {
        std::unordered_map<long long, long long> mp;
        std::set<std::pair<long, long>, std::greater<std::pair<long, long>>> s;

        int n = nums.size();
        std::vector<long long> ans(n, INT_MIN);

        for(int i = 0; i < n; i++){
            long long elm = nums[i];
            std::pair<long, long> p = {mp[elm], elm};
            if(s.find(p) != s.end()) s.erase(p);

            mp[elm] += freq[i];
            p = {mp[elm], elm};
            s.insert(p);
            auto max_freq =*s.begin();
            ans[i] = max_freq.first;
        }

        return ans;
    }
};