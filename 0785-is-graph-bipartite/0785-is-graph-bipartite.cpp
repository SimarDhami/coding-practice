class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int node = 0; node < n; node++){
            if(color[node] != 0) continue;

            queue<int> q;
            q.push(node);
            color[node] = 1;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(int adj : graph[curr]){
                    if(color[adj] == 0){
                        color[adj] = -color[curr];
                        q.push(adj);
                    }
                    else if(color[adj] == color[curr]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};