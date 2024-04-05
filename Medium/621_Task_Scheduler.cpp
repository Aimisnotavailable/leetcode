#include <vector>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        
        std::vector<int> task_count(26, 0); 
        
        for (char task : tasks)
            task_count[task - 'A']++; 
        
        std::sort(task_count.begin(), task_count.end(), std::greater<int>());
        
        int max_freq = task_count[0]; 
        
        int num_max_freq_tasks = std::count(task_count.begin(), task_count.end(), max_freq);
   
        int intervals_needed = (max_freq - 1) * (n + 1) + num_max_freq_tasks;

        task_count.clear();
        return std::max(intervals_needed, static_cast<int>(tasks.size()));
    }
};