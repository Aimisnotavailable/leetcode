#include<stack>
#include<string>
#include<algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> stack;
        
        for (char digit : num) {
            // Only pops if the current top is higher than the next digit
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        // Removes the least significant digit if the most significant digits increases 'til the least significant digits
        // E.G. 12345 removing elements on the with higher significance will only increase the value of the number
        // Compared to removing digits in the least significant position
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        std::reverse(result.begin(), result.end());
        
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};
