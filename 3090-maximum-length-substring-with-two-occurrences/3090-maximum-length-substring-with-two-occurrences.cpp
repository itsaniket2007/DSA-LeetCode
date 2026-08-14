class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, maxLength = 0;
        int count[26] = {0};

        for (int right = 0; right < s.length(); ++right) {
            int charIdx = s[right] - 'a';
            count[charIdx]++;
            while (count[charIdx] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};