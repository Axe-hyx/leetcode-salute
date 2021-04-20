/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
class LRUCache {

public:
  LRUCache(int cap) : cap(cap) {}
  int cap;
  list<pair<int, int>> lists;

  unordered_map<int, list<pair<int, int>>::iterator> maps;

  int get(int key) {
    if (!maps.count(key))
      return -1;
    pair<int, int> p = *maps[key];
    lists.erase(maps[key]);
    lists.push_front(p);
    maps[key] = lists.begin();
    return lists.front().second;
  }
  void put(int key, int val) {
      if(maps.find(key) == maps.end()) {
      if (cap == maps.size()) {
        maps.erase(lists.back().first);
        lists.pop_back();
      }
      } else {
        lists.erase(maps[key]);
        maps.erase(key);
      }
      pair<int, int> p = make_pair(key, val);
      lists.push_front(p);
      maps[key] = lists.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char **argv) {
  /*
{
  LRUCache sol(2);
  sol.put(1, 1);
  sol.put(2, 2);
  help(sol.get(1));
  sol.put(3, 3);
  help(sol.get(2));
  sol.put(4, 4);
  help(sol.get(1));
  help(sol.get(3));
  help(sol.get(4));
}
*/
  {
    LRUCache sol(2);
    sol.put(2, 1);
    sol.put(1, 1);
    sol.put(2, 3);
    sol.put(4, 1);
    help(sol.get(1));
    help(sol.get(2));
  }
  return 0;
}
// @lc code=end
