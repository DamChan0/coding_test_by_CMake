#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> v) {
  vector<int> ans;

  int hindex = 0;
  int hdistance = 0;
  int vindex = 0;
  int vdistance = 0;

  for (int i = 1; i < v.size(); i++) {
    if (v[i][0] == v[0][0]) {
      vindex = i;
      vdistance = abs(v[i][1] - v[0][1]);
      break;
    } else if (v[i][1] == v[0][1]) {
      hindex = i;
      hdistance = abs(v[i][0] - v[0][0]);
      break;
    }
  }

  if (hindex != 0) {
    for (int i = 1; i < v.size(); i++) {
      if (i != hindex) {
        if (v[0][0] < v[i][0]) {
          ans = {v[i][0] - hdistance, v[i][1]};
          break;
        } else if (v[0][0] > v[i][0]) {
          ans = {v[i][0] + hdistance, v[i][1]};
          break;
        }
      }
    }
  }

  if (vindex != 0) {
    for (int i = 1; i < v.size(); i++) {
      if (i != vindex) {
        if (v[0][1] < v[i][1]) {
          ans = {v[i][0], v[i][1] - vdistance};
          break;
        } else if (v[0][1] > v[i][1]) {
          ans = {v[i][0], v[i][1] + vdistance};
          break;
        }
      }
    }
  }
  return ans;
}
