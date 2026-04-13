class Solution {
public:
    string findOrder(vector<string> &words) {
        int K = 26; // max letters

        vector<vector<int>> adj(K);
        vector<int> indegree(K, 0);
        vector<int> present(K, 0);

        // mark present characters
        for (auto &word : words) {
            for (char c : word) {
                present[c - 'a'] = 1;
            }
        }

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            // invalid case
            if (!found && w1.size() > w2.size())
                return "";
        }

        // topo sort
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }

        string result = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result += (char)(node + 'a');

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // count present chars
        int count = 0;
        for (int i = 0; i < K; i++)
            if (present[i]) count++;

        if (result.size() != count)
            return ""; // cycle

        return result;
    }
};