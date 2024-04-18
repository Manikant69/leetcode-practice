class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        //adj list
        unordered_map<int, list<pair<int, int>>> adj;
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> dist(n, -1);
        vector<int> vis(n, false);
        
        int s = 0;
        dist[s] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, s});
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            int d = top.first;
            int node = top.second;

            if(vis[node] || d >= disappear[node])
                continue;

            dist[node] = d;
            vis[node] = true;
            
            for(auto neighbour : adj[node]){
                if(!vis[neighbour.first]){
                    pq.push({d+neighbour.second, neighbour.first});
                }
            }
            
        }
        
       return dist; 
    }
};
