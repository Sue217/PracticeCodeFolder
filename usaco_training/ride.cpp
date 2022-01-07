/*
ID: sujingb1
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1, s2;
    fin >> s1 >> s2;
    int val1 = 1, val2 = 1;
    for (auto s : s1) {
        val1 *= (s - 'A' + 1);
    }
    for (auto s : s2) {
        val2 *= (s - 'A' + 1);
    }
    if (val1 % 47 == val2 % 47) {
        fout << "GO" << '\n';
    } else {
        fout << "STAY" << '\n';
    }
    return 0;
}
