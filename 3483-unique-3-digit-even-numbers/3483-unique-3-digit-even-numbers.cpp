class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) count[d]++;
        int ans = 0;
        for (int i = 100; i < 1000; i += 2) {
            int c[10] = {0};
            int temp = i;
            while (temp > 0) {
                c[temp % 10]++;
                temp /= 10;
            }
            bool possible = true;
            for (int j = 0; j < 10; ++j) {
                if (c[j] > count[j]) {
                    possible = false;
                    break;
                }
            }
            if (possible) ans++;
        }
        return ans;
    }
};