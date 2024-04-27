class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        int temp = x;
        long long int y  = 0;
        while(temp > 0){
            int r = temp % 10;
            temp = temp / 10;
            y = (y * 10) + r;
        }
        return (y == x);
    }
};