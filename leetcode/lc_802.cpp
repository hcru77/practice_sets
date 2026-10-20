class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> adjList(N);
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {   // We want to see incoming nodes rather than outoing
            for (int curNeighbor : graph[i]) {
                adjList[curNeighbor].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> ejectionQueue;
        vector<int> safeNodes;

        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {     //terminal node
                ejectionQueue.push(i);
            }
        }

        while(!ejectionQueue.empty()) {
            int curNode = ejectionQueue.front();
            ejectionQueue.pop();
            safeNodes.push_back(curNode);
            for (auto neighbor : adjList[curNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    ejectionQueue.push(neighbor);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    } 
};
