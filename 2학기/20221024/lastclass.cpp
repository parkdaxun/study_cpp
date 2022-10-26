void Dijkstra_PriorityQueue() {
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push(make_pair(0, start));
    while(!q.emplty()) {
        int cur_dist = -q.top().first;
        int cur_node = q.top().second;
        q.pop();
        if(cur_dist > dist[cur_node]) continue;

        for(int i=0; i<graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_node = 
        }
    }
}