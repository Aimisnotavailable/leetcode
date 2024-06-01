class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'M')
                num += 1000;
            else if(s[i] == 'D')
                num += 500;
            else if(s[i] == 'C'){
                if(i + 1 < s.size()){
                    if(s[i + 1] == 'M'){
                        num += 900;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'D'){
                        num += 400;
                        i++;
                        continue;
                    }
                }
                num += 100;
            }
            else if(s[i] == 'L')
                num += 50;
            else if(s[i] == 'X'){
                if(i + 1 < s.size()){
                    if(s[i + 1] == 'C'){
                        num += 90;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'L'){
                        num += 40;
                        i++;
                        continue;
                    }
                }
                num += 10;
            }
            else if(s[i] == 'V')
                num += 5;
            else if(s[i] == 'I'){
                if(i + 1 < s.size()){
                    if(s[i + 1] == 'X'){
                        num += 9;
                        i++;
                        continue;
                    }
                    else if(s[i + 1] == 'V'){
                        num += 4;
                        i++;
                        continue;
                    }
                }
                num += 1;
            }                
        }
        return num;
    }
};
