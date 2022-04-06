// key point : Dijkstra Algorithm

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147000000

int n, m, x;
int matrix[1001][1001];

struct Node {
    int num;
    bool visited;
    vector<pair<int, Node*>> adjList;
    Node(int num) {
        this->num = num;
        this->visited = false;
    }
};

class Graph {
public:
    vector<Node*> nodeList;
    Graph() {
        nodeList.push_back(0);
        for (int i = 1; i <= n; i++) {
            Node* newNode = new Node(i);
            nodeList.push_back(newNode);
        }
    }

    void clear() {
        for (int i = 1; i <= n; i++)
            nodeList[i]->visited = false;
    }

    void link(int a, int b, int c) {
        nodeList[a]->adjList.push_back({ c, nodeList[b] });
    }

    void Dijkstra(int start) {
        clear();
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        pq.push({ 0, nodeList[start] });
        pair<int, Node*> cur;
        for (int i = 1; i <= n; i++) {
            cur = pq.top();
            pq.pop();
            while (cur.second->visited) {
                cur = pq.top();
                pq.pop();
            }

            matrix[start][cur.second->num] = cur.first;
            cur.second->visited = true;

            for (int j = 0; j < cur.second->adjList.size(); j++) {
                if (!cur.second->adjList[j].second->visited) {
                    pq.push({ cur.first + cur.second->adjList[j].first, cur.second->adjList[j].second });
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    Graph g;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g.link(a, b, c);
    }
    for (int i = 1; i <= n; i++)
        g.Dijkstra(i);

    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, matrix[i][x] + matrix[x][i]);
    cout << result;

    return 0;
}