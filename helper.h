#ifndef __HELPER_H__
#define __HELPER_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void help(const vector<vector<int>> &nums, const string& str = "") {
  if (str != "") {
    cout << str << endl;
  }
  for (auto num : nums) {
    for (auto v : num) {
      cout << v << " ";
    }
    cout << endl;
  }
}
void help(const vector<int> &nums, const string &str = "") {
  if (str != "") {
    cout << str << endl;
  }
  for (auto v : nums) {
    cout << v << " ";
  }
  cout << endl;
}
void help(const int &num, const string &str = "") {
  if (str != "") {
    cout << str << endl;
  }
  cout<<num;
  cout << endl;
}

#endif
