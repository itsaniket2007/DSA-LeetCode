class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long total_commas = 0;
        long long start = 1000;
        long long commas = 1;
        while (start <= n) {
            long long end = start * 1000 - 1;
            long long count = min(n, end) - start + 1;
            if (count > 0) {
                total_commas += count * commas;
            }
            start *= 1000;
            commas++;
        }
        return total_commas;
    }
};