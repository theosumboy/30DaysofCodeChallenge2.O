class Solution {
const int N = 5 * 1e4 + 5;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> dp(N, 0), adj[N], in(N, 0);
        int ans = 0;
        for(int i = 0; i < relations.size(); i++){
            int x = relations[i][0], y = relations[i][1];
            adj[x].push_back(y);
            in[y]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(!in[i]){
                dp[i] = time[i-1];
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                in[v]--;
                dp[v] = max(dp[v], dp[u] + time[v-1]);
                if(in[v] == 0){
                    q.push(v);
                }
            }
        }
        for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        return ans;
    }
};
