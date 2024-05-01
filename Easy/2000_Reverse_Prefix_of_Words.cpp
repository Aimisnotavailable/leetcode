class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find(ch);
        std::reverse(word.begin(), word.begin() + i + 1);
        return word;
    }
};
