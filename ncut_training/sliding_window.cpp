/**
 *    author: subobo
 *    created: 18.01.2022 20:43:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> seq(n);
  for (auto& in : seq) {
    cin >> in;
  }
  auto slidingWindowSmallest = [&](vector<int>& nums, int k) {
    vector<int> res;
    deque<int> window;
    for (int i = 0; i < (int) nums.size(); i++) {
      if (!window.empty() and window.front() < i - k + 1) {
        window.pop_front();
      }
      while (!window.empty() and nums[window.back()] >= nums[i]) {
        window.pop_back();
      }
      window.push_back(i);
      if (i - k + 1 >= 0) {
        res.emplace_back(nums[window.front()]);
      }
    }
    return res;
  };
  auto slidingWindowLargest = [&](vector<int> nums, int k) {
    vector<int> res;
    deque<int> window;
    for (int i = 0; i < (int) nums.size(); i++) {
      if (!window.empty() and window.front() < i - k + 1) {
        window.pop_front();
      }
      while (!window.empty() and nums[window.back()] <= nums[i]) {
        window.pop_back();
      }
      window.push_back(i);
      if (i - k + 1 >= 0) {
        res.emplace_back(nums[window.front()]);
      }
    }
    return res;
  };
  vector<int> ans = slidingWindowSmallest(seq, k);
  for (auto it : ans) {
    cout << it << " ";
  }
  ans.clear();
  cout << '\n';
  ans = slidingWindowLargest(seq, k);
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << '\n';
  return 0;
}