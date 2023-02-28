class Solution
{
    // Network delay solution
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : times)
        {
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
        }
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[k - 1] = 0;
        pq.push({0, k - 1});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adj_dis = it.second;
                int adj_node = it.first;
                if (dist + adj_dis < dis[adj_node])
                {
                    dis[adj_node] = dist + adj_dis;
                    pq.push({dis[adj_node], adj_node});
                }
            }
        }

        int ans = 0;
        for (auto it : dis)
        {
            ans = max(ans, it);
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};