//2021/8/23
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int ans = -1;
        for (const auto &edge : edges) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }

        //Floyd-Warshall's
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (dist[j][i] < INT_MAX && dist[i][k] < INT_MAX) {
                        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }    
                }
            }
        }
        
        for (int i = 0, min = INT_MAX; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= min) {
                ans = i;
                min = count;
            }
        }

        return ans;
    }
};