#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        std::string current = "";
        if (dfs(0, true, count, target, current)) {
            return current;
        }
        return "";
    }
private:
    bool dfs(int idx, bool is_tight, std::vector<int>& count, const std::string& target, std::string& current) {
        int n = target.length();
        if (idx == n) {
            return true; 
        }
        int start_char = is_tight ? (target[idx] - 'a') : 0;
        for (int c = start_char; c < 26; ++c) {
            if (count[c] > 0) {
                bool next_tight = is_tight && (c == target[idx] - 'a');
                if (idx == n - 1 && next_tight) {
                    continue;
                }
                count[c]--;
                current.push_back('a' + c);
                if (dfs(idx + 1, next_tight, count, target, current)) {
                    return true;
                }
                current.pop_back();
                count[c]++;
            }
        }
        return false;
    }
};