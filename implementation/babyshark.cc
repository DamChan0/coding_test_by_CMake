#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

int V, E, K;
vector<pair<int, int>> adj[20001]; // 인접 리스트 (정점, 가중치)
vector<int> dist;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode])
            continue;

        for (auto &edge : adj[currentNode])
        {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[currentNode] + weight < dist[nextNode])
            {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> K;
    dist.resize(V + 1, INF); // 거리 배열 (인덱스 1부터 시작) inf 는 왜한거지 :

    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(K);

    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
