#include <bits/stdc++.h>
using namespace std;

struct Item {
    double value, weight;
    double ratio;
};

int n;
double maxW, best = 0.0;
vector<Item> items;

bool cmp(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

double getBound(int idx, double curW, double curV) {
    double bound = curV;
    for (int i = idx; i < n; i++) {
        if (curW + items[i].weight <= maxW) {
            curW += items[i].weight;
            bound += items[i].value;
        } else {
            double remain = maxW - curW;
            bound += items[i].value * (remain / items[i].weight); 
            break;
        }
    }
    return bound;
}

void dfs(int idx, double curW, double curV) {
    if (curW > maxW) return;
    if (idx == n) {
        best = max(best, curV);
        return;
    }

    double bound = getBound(idx, curW, curV);
    if (bound <= best) return;  

    dfs(idx + 1, curW + items[idx].weight, curV + items[idx].value);
    dfs(idx + 1, curW, curV);
}

int main() {
    cin >> maxW >> n;
    items.resize(n);
    for (int i = 0; i < n; i++) cin >> items[i].value;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), cmp);

    dfs(0, 0.0, 0.0);

    cout << fixed << setprecision(4) << best << endl;
}
