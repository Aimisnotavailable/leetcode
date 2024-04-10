#include<queue>
class RecentCounter {
public:
    std::queue<int> calls;
    int count = 0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int min = t - 3000;
        calls.push(t);
        count++;
        
        while(calls.front() < min){
            count--;
            calls.pop();
        }

        return count;
    }

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */