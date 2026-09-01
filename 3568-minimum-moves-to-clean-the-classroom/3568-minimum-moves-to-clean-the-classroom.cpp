#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int start_x = -1, start_y = -1;
        vector<pair<int, int>> litters;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        int total_litter = litters.size();
        int full_mask = (1 << total_litter) - 1;
        static int bestEnergy[20][20][1024];
        memset(bestEnergy, -1, sizeof(bestEnergy));
        queue<tuple<int, int, int, int, int>> q;
        int initial_mask = 0;
        for (int i = 0; i < total_litter; ++i) {
            if (litters[i].first == start_x && litters[i].second == start_y) {
                initial_mask |= (1 << i);
            }
        }
        q.push({start_x, start_y, initial_mask, energy, 0});
        bestEnergy[start_x][start_y][initial_mask] = energy;       
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y, mask, curr_e, steps] = q.front();
            q.pop();    
            if (mask == full_mask) {
                return steps;
            }
            if (curr_e < bestEnergy[x][y][mask]) {
                continue;
            } 
            for (int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];  
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (classroom[nx][ny] == 'X') continue;
                
                int next_e = curr_e - 1;
                if (next_e < 0) continue;
            }
        }
        queue<tuple<int, int, int, int, int>>().swap(q);
        q.push({start_x, start_y, initial_mask, energy, 0});
        bestEnergy[start_x][start_y][initial_mask] = energy;
        while (!q.empty()) {
            auto [x, y, mask, curr_e, steps] = q.front();
            q.pop();
            if (mask == full_mask) return steps;
            if (curr_e < bestEnergy[x][y][mask]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (classroom[nx][ny] == 'X') continue;
                int next_e = curr_e - 1;
                if (next_e < 0) continue;
                int next_mask = mask;
                char cell_type = classroom[nx][ny];
                for (int l_idx = 0; l_idx < total_litter; ++l_idx) {
                    if (litters[l_idx].first == nx && litters[l_idx].second == ny) {
                        next_mask |= (1 << l_idx);
                        break;
                    }
                }
                if (cell_type == 'R') {
                    next_e = energy;
                }
                
                if (next_e > bestEnergy[nx][ny][next_mask]) {
                    bestEnergy[nx][ny][next_mask] = next_e;
                    q.push({nx, ny, next_mask, next_e, steps + 1});
                }
            }
        }
        return -1;
    }
};