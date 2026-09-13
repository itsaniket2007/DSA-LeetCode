class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int n = 0, int m = 0) {
        vector<int> l1, l2;
        for (int i = 0, n = img1.size(); i < n * n; ++i) {
            if (img1[i / n][i % n]) l1.push_back((i / n) * 100 + (i % n));
            if (img2[i / n][i % n]) l2.push_back((i / n) * 100 + (i % n));
        }
        unordered_map<int, int> mtx;
        for (int p1 : l1) for (int p2 : l2) mtx[p1 - p2]++;
        for (auto& [k, v] : mtx) m = max(m, v);
        return m;
    }
};