class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        vector<int> pos(n), sortedVal(n);
        for (int i = 0; i < n; i++) {
            pos[idx[i]] = i;
            sortedVal[i] = nums[idx[i]];
        }

        // right[i] = furthest sorted position reachable directly from i (two-pointer)
        vector<int> right(n);
        {
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (j < i) j = i;
                while (j + 1 < n && sortedVal[j+1] - sortedVal[i] <= maxDiff) j++;
                right[i] = j;
            }
        }

        // DSU over sorted positions for connectivity
        vector<int> parent(n), rnk(n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (rnk[a] < rnk[b]) swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
        };
        for (int i = 0; i + 1 < n; i++)
            if (sortedVal[i+1] - sortedVal[i] <= maxDiff) unite(i, i+1);

        // Binary lifting table
        const int LOG = 18; // 2^17 > 1e5
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = right;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k-1][ up[k-1][i] ];

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) { ans[i] = 0; continue; }
            int pu = pos[u], pv = pos[v];
            if (find(pu) != find(pv)) { ans[i] = -1; continue; }
            int a = min(pu, pv), b = max(pu, pv);
            int cur = a, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }
            ans[i] = steps + 1; // final jump reaches/exceeds b
        }
        return ans;
    }
};