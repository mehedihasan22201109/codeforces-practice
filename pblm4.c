
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int vertex_count;
        cin >> vertex_count;

        unordered_map<int, vector<pair<int, int>>> conn;
        for (int i = 0; i < vertex_count - 1; ++i) {
            int u, v;
            cin >> u >> v;
            conn[u].emplace_back(v, i);
            conn[v].emplace_back(u, i);
        }

        int pivot = -1;
        for (int node = 1; node <= vertex_count; ++node) {
            if (conn[node].size() == 2) {
                pivot = node;
                break;
            }
        }
        if (pivot == -1) {
            cout << "NO\n";
            continue;
        }

        auto [n1, id1] = conn[pivot][0];
        auto [n2, id2] = conn[pivot][1];

        vector<bool> used(vertex_count - 1, false);
        vector<pair<int, int>> links;

        used[id1] = true;
        used[id2] = true;
        links.emplace_back(n1, pivot);
        links.emplace_back(pivot, n2);

        stack<tuple<int, int, bool>> stk;
        stk.emplace(n1, pivot, true);
        stk.emplace(n2, pivot, false);

        while (!stk.empty()) {
            auto [curr, prev, flip] = stk.top();
            stk.pop();
            for (auto &[adj, edge_id] : conn[curr]) {
                if (used[edge_id]) continue;
                used[edge_id] = true;
                if (flip) {
                    links.emplace_back(curr, adj);
                    stk.emplace(adj, curr, false);
                } else {
                    links.emplace_back(adj, curr);
                    stk.emplace(adj, curr, true);
                }
            }
        }

        cout << "YES\n";
        for (auto &[a, b] : links) {
            cout << a << " " << b << "\n";
        }
    }

    return 0;
}

