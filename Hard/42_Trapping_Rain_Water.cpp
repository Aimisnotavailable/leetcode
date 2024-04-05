#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        int trapped = 0;
        if(n >= 1 && n <= 2 * pow(10,4)){
            int start = 0;
            while(true && start < n){
                if(height[start] == 0){
                    start++;
                    continue;
                }
                break;  
            }
            while(start < n){
                int r_dim;
                int l_dim = height[start];
                int s_apex = -1;
                int s_apex_ind = -1;
                std::cout << "ITERATION : ";
                for(int i = start + 1; i < n; i++){
                    if(height[i] < 0)
                        return -1;
                    if(height[i] >= l_dim){
                        r_dim = height[i];
                        std::cout << "start: " << start << " left_dim: " << l_dim << " right_dim: " << r_dim << std::endl;
                        int v_bound = (l_dim < r_dim) ? l_dim : r_dim;
                        for(int j = start; j < i; j++){
                            trapped += (v_bound - height[j]);
                        }
                        start = i;
                        l_dim = r_dim;
                        s_apex = -1;
                        s_apex_ind = -1;
                        continue;
                    }else{
                        if(height[i] >= s_apex || s_apex == -1){   
                            s_apex = height[i];
                            s_apex_ind = i;
                        }
                        if((i + 1) == n && (s_apex_ind - start) > 1){
                            r_dim = s_apex;
                            int v_bound = (l_dim < r_dim) ? l_dim : r_dim;
                            
                            for(int j = start + 1; j < s_apex_ind; j++){
                                trapped += (v_bound - height[j]);
                            }
                            start = s_apex_ind - 1;
                            l_dim = r_dim;
                        }
                    }
                }
                start++;
            } 
            
        }
        height.clear();
        return trapped;
    }
};