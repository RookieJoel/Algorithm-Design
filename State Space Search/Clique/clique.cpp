#include <bits/stdc++.h>
using namespace std;

int n, maxPower = 0;
vector<int> B;
vector<vector<int>> F;

struct Person {
    int idx, ability;
    bool operator<(const Person& other) const {
        return ability > other.ability; // sort decreasing
    }
};

void dfs(vector<int>& clique, int pos, int curSum, const vector<Person>& people) {
    maxPower = max(maxPower, curSum);

    for (int i = pos; i < people.size(); ++i) {
        int candidate = people[i].idx;

        // check if candidate is friend with everyone in clique
        bool ok = true;
        for (int member : clique) {
            if (F[candidate][member] == 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            clique.push_back(candidate);
            dfs(clique, i + 1, curSum + B[candidate], people);
            clique.pop_back();
        }
    }
}

int main() {
    cin >> n;
    B.resize(n);
    F.assign(n, vector<int>(n));

    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> F[i][j];

    // prepare people list sorted by ability
    vector<Person> people(n);
    for (int i = 0; i < n; ++i)
        people[i] = {i, B[i]};
    sort(people.begin(), people.end());

    vector<int> clique;
    dfs(clique, 0, 0, people);

    cout << maxPower << endl;
}
