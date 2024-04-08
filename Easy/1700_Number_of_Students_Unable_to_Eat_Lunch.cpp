#include<vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int i = 0;
        int count = 0;

        while(i != sandwiches.size()){
            if(sandwiches[i] == students[0]){
                students.erase(students.begin());
                i++;
                count = 0;
            }else{
                int temp = students[0];
                students.erase(students.begin());
                students.push_back(temp);
                count++;
            }
            if(count >= students.size())
                return sandwiches.size() - i;
        }

        return sandwiches.size() - i;
    }
};