class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, graph, path, res);
        return res;
    }

    void dfs(int v, vector<vector<int>>& graph, vector<int> path, vector<vector<int>>& res) {
        path.push_back(v);
        
        if (v == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < graph[v].size(); i++)
            dfs(graph[v][i], graph, path, res);
    }
};