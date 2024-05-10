#include <vector>
#include <map>
class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        std::map <long double, std::vector<int>> a;
        
        int i = 0, j = 0, n = arr.size();
        
        while(i < n - 1){
            j = i + 1;
            long double num = arr[i++];
            std::vector<int> temp;
            temp.push_back(num);
            while(j < n){
                long double denum = arr[j++];
                temp.push_back(denum);
                a[num/denum] = temp;
                temp.pop_back();
            }
        }
        
        
        int c = 1;
        std::cout << k;
        for(const auto& pair : a){
           if(c == k){
                return pair.second;
            }
            c++;
        }
        return arr;
    }
};
