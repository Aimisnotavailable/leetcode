#include<vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> a;
        int left = 0;
        int right = 0;

        while(left != nums1.size() || right != nums2.size()){
            if(left != nums1.size() && right != nums2.size()){
                if(nums1[left] < nums2[right])
                    a.push_back(nums1[left++]);
                else
                    a.push_back(nums2[right++]);
            }else if(left < nums1.size())
                a.push_back(nums1[left++]);
            else
                a.push_back(nums2[right++]);
        }
        
        int len = a.size();
        int mp = len / 2;
        double median = (len % 2 == 0) ? static_cast<double>((a[mp] + a[mp-1]))/ 2 : a[mp];

        return median;
    }
};