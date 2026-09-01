struct node {
    int r, c;
    int energy;
    int mask;
    int steps;
};

class Solution {
public:

    bool visited[21][21][51][1<<10];
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        // Store the number of each litter
        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = cnt;
                    cnt++;
                }
            }
        }

        int all = (1 << cnt) - 1;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        memset(visited,false,sizeof(visited));

        queue<node> q;

        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        while(!q.empty()) {

            node cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int en = cur.energy;
            int mask = cur.mask;
            int steps = cur.steps;

            // All litter collected
            if(mask == all)
                return steps;

            for(auto d : dir) {

                int nr = r + d.first;
                int nc = c + d.second;

                // Outside the classroom
                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Wall
                if(classroom[nr][nc] == 'X')
                    continue;

                // No energy to move
                if(en == 0)
                    continue;

                int newEnergy = en - 1;
                int newMask = mask;

                // Found litter
                if(classroom[nr][nc] == 'L') {
                    int x = id[nr][nc];
                    newMask = mask | (1 << x);
                }

                // Recharge
                if(classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // If we haven't seen this exact state
                if(!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({ nr, nc, newEnergy, newMask, steps + 1 });
                }
            }
        }

        return -1;
    }
};