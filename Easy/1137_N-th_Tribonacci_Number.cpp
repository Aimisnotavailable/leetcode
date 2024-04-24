class Solution {
public:
    int tribonacci(int n) {
        int f[38] = {0};
        f[0] = 0;
        f[1] = 1;
        f[2] = 1;
        if(n < 3)
            return f[n];

        for(int i = 3; i < 38; i++){
            f[i] = f[i - 3] + f[i - 2] + f[i - 1];
        }
        
        return f[n];
    }
};
