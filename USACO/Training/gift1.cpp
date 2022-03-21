/*
ID: sujingb1
TASK: gift1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int tt;
    fin >> tt;
    unordered_map<string, int> save;
    vector<string> s;
    for (int i = 0; i < tt; i++) {
        string name;
        fin >> name;
        save[name] = 0;
        s.emplace_back(name);
    }
    for (int i = 0; i < tt; i++) {
        string name;
        fin >> name;
        int cost, div;
        fin >> cost >> div;
        if (!div) {
            save[name] -= cost;
        } else {
            int remain = cost % div;
            save[name] = save[name] - cost + remain;
        }
        for (int j = 0; j < div; j++) {
            string div_name;
            fin >> div_name;
            save[div_name] += cost / div;
        }
    }
    for (auto i : s) {
        fout << i << " " << save[i] << '\n';
    }
    return 0;
}
