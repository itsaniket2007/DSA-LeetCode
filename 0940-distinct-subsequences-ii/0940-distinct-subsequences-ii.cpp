class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        vector<long long> last(26, 0);
        long long total = 0;
        for (char c : s) {
            int idx = c - 'a';
            long long new_subseqs = (total + 1 - last[idx] + MOD) % MOD;
            total = (total + new_subseqs) % MOD;
            last[idx] = (last[idx] + new_subseqs) % MOD;
        }
        return total;
    }
};