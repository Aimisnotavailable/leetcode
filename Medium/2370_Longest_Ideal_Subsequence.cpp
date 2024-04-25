#include <string>
#include <algorithm>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        int dp[27] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = -__INT_MAX__;

            int left = std::max((idx - k), 0);
            int right = std::min((idx + k), 26);

            for (int j = left; j <= right; j++) {
                maxi = std::max(maxi, dp[j]);
            }

            dp[idx] = maxi + 1;
        }

        int max = -__INT_MAX__;
        for (int i = 0; i < 27; i++) {
            if (dp[i] > max)
                max = dp[i];
        }

        return max;
    }
};