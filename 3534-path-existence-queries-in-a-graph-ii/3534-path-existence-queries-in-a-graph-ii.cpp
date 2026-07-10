#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        vector<int> pos_in_sorted(n);
        for (int i = 0; i < n; ++i) {
            pos_in_sorted[sorted_nodes[i].second] = i;
        }

        int max_levels = log2(n) + 1;
        vector<vector<int>> up_right(n, vector<int>(max_levels));
        for (int i = 0; i < n; ++i) {
            int target_val = sorted_nodes[i].first + maxDiff;
            auto it = upper_bound(sorted_nodes.begin(), sorted_nodes.end(), make_pair(target_val, n));
            int next_idx = distance(sorted_nodes.begin(), it) - 1;
            up_right[i][0] = next_idx;
        }

        for (int k = 1; k < max_levels; ++k) {
            for (int i = 0; i < n; ++i) {
                up_right[i][k] = up_right[up_right[i][k-1]][k - 1];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int idx_u = pos_in_sorted[u];
            int idx_v = pos_in_sorted[v];
            if (idx_u > idx_v) {
                swap(idx_u, idx_v);
            }

            int steps = 0;
            for (int k = max_levels - 1; k >= 0; --k) {
                if (up_right[idx_u][k] < idx_v && up_right[idx_u][k] > idx_u) {
                    steps += (1 << k);
                    idx_u = up_right[idx_u][k];
                }
            }

            if (up_right[idx_u][0] >= idx_v) {
                answer.push_back(steps + 1);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};