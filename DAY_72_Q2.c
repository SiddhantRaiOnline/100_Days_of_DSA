class Solution {
public:
    int n;
    int dp[1<<15][15];

    // helper function
    int solve(int mask, int pos, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1)
            return cost[pos][0];

        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ans = INT_MAX;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newCost = cost[pos][city] +
                              solve(mask | (1 << city), city, cost);

                if (newCost < ans)
                    ans = newCost;
            }
        }

        return dp[mask][pos] = ans;
    }

    // THIS is what driver calls
    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));

        return solve(1, 0, cost); // start from city 0
    }
};