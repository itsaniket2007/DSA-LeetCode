#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, -1));

        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) return d;

            if (dist[u][count] != -1 && dist[u][count] < d) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;

                if (next_count <= k) {
                    if (dist[v][next_count] == -1 || d + w < dist[v][next_count]) {
                        dist[v][next_count] = d + w;
                        pq.push({d + w, v, next_count});
                    }
                }
            }
        }

        return -1;
    }
};