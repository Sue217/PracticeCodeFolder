/*
ID: sujingb1
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;
    constexpr int start_year = 1900;
    int days = 1;
    vector<int> thirteen(7);
    for (int year = start_year; year < start_year + n; year++) {
        if (year % 4 == 0 and (not(year % 100 == 0) or (year % 400 == 0))) {
            vector<int> date({31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
            for (int month = 0; month < 12; month++) {
                int t = days + date[month];
                thirteen[(days + 12) % 7]++;
                days = t % 7;
            }
        } else {
            vector<int> date({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
            for (int month = 0; month < 12; month++) {
                int t = days + date[month];
                thirteen[(days + 12) % 7]++;
                days = t % 7;
            }
        }
    }
    rotate(thirteen.begin(), thirteen.begin() + 6, thirteen.end());
    for (int it = 0; it < 6; it++) {
        fout << thirteen[it] << " ";
    }
	fout << *thirteen.rbegin() << '\n';
    return 0;
}
