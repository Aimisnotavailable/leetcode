
#include<vector>
#include<queue>
#include<algorithm>

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        int n = deck.size();
        std::sort(deck.begin(), deck.end());
        std::queue<int> a;
        std::vector<int> result(n);

        for(int i = 0; i < n; i++){
            a.push(i);
        }

        for(int i = 0; i < n; i++){
            result[a.front()] = deck[i];
            a.pop();

            if(!a.empty()){
                a.push(a.front());
                a.pop();
            }
        }

        return result;
    }
};