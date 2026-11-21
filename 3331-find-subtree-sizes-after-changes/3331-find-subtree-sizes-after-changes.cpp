class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) adj[parent[i]].push_back(i);

        // Pack (depth << 18) | node_id since n <= 1e5 (18 bits hold up to 262,143)
        array<int, 26> info{};
        info.fill(-1);
        vector<int> new_parent = parent, sz(n, 1);

        auto find_anc = [&](auto& self, int u, int d) -> void {
            int c = s[u] - 'a', prev = info[c];
            if (prev != -1) new_parent[u] = prev & ((1 << 18) - 1);
            info[c] = (d << 18) | u;
            for (int v : adj[u]) self(self, v, d + 1);
            info[c] = prev;
        };
        find_anc(find_anc, 0, 0);

        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) final_adj[new_parent[i]].push_back(i);

        auto count_sz = [&](auto& self, int u) -> int {
            for (int v : final_adj[u]) sz[u] += self(self, v);
            return sz[u];
        };
        count_sz(count_sz, 0);
        return sz;
    }
};