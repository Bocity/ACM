#include <string.h>
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define int long long
int a[15];
int b[15];
main() {
  for (int i = 0; i < 14; i++) {
    int x;
    cin >> a[i];
    b[i] = a[i];
  }
  int ans = 0;
  int maxx = -1;
  for (int i = 0; i < 14; i++) {
    if (a[i] % 2 == 1) {
      ans = 0;
      int t = i + 1;
      int ccc = a[i];
      if (t == 14) {
        t = 0;
      }
      a[i] = 0;
      int count = 0;
      while (ccc--) {
        a[t]++;
        count++;
        t++;
        if (t == 14) {
          t = 0;
        }
        if (ccc == 0) {
          break;
        }
      }
      // if (i == 9) {
      //   for (int k = 0; k < 14; k++) {
      //     cout << a[k] << " ";
      //   }
      //   // return 0;
      //   cout << endl;
      // }
      for (int j = 0; j < 14; j++) {
        if (a[j] % 2 == 0) {
          ans += a[j];
        }
      }
      if (ans > maxx) {
        maxx = ans;
      }
    }
    for (int k = 0; k < 14; k++) {
      a[k] = b[k];
    }
  }
  cout << maxx << endl;
  return 0;
}