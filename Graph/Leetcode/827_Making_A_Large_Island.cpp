//2021/8/1
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0, color = 2;
        unordered_map<int, int> areaMap;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    Bfs(grid, areaMap, i, j, color);
                    ans = max(ans, areaMap[color]);
                    ++color;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> connected;
                    for (const auto &dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            connected.insert(grid[x][y]);
                        }
                    }
                    int area = 0;
                    for (auto connect : connected) {
                        area+=areaMap[connect];
                    }
                    ans = max(ans, area + 1);
                }
            }
        }
        
        return ans;
    }
private:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void Bfs(vector<vector<int>> &grid, unordered_map<int, int> &areaMap, int i, int j, int color) const
    {
        queue<pair<int, int>> Q;
        Q.push(make_pair(i, j));
        grid[i][j] = color;
        int area = 0, n = grid.size();
        while (!Q.empty()) {
            auto cor = Q.front();
            Q.pop();
            ++area;
            for (const auto &dir : dirs) {
                int x = cor.first + dir[0], y = cor.second + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                    grid[x][y] = color;
                    Q.push(make_pair(x, y));
                } 
            }
        }
        areaMap[color] = area;
    }
};