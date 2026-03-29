class Solution {
public:
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>&q,
             vector<vector<bool>>& vis) {
       

        int delr[4] = {0, -1, 0, 1};
        int delc[4] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = r + delr[i];
                int col = c + delc[i];

                if (row >= 0 && row < heights.size() && col >= 0 &&
                    col < heights[0].size() && vis[row][col] != true) {
                    if (heights[r][c] <= heights[row][col]) {

                        vis[row][col] = true;
                        q.push({row, col});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        vector<vector<bool>> vis1(heights.size(),
                                  vector<bool>(heights[0].size(), false));
        vector<vector<bool>> vis2(heights.size(),
                                  vector<bool>(heights[0].size(), false));

                                   queue<pair<int, int>> q1;
                                    queue<pair<int, int>> q2;

        for (int i = 0; i < heights.size(); i++) {
q1.push({i,0});
q2.push({i,heights[0].size()-1});
vis1[i][0]=true;
vis2[i][heights[0].size() - 1]=true;
           
        }
        for (int j = 0; j < heights[0].size(); j++) {
            q1.push({0,j});
            q2.push({heights.size()-1,j});
            vis1[0][j]=true;
            vis2[heights.size()-1][j]=true;

        }

        bfs(heights, q1, vis1);
        bfs(heights,q2,vis2);

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (vis1[i][j] && vis2[i][j]) {
                    vector<int> temp = {i, j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
