#include <bits/stdc++.h>
using namespace std;

// めぐる式
int binary() {
  int ok = 0, ng = 1;
  auto solve = [](int m) -> bool {
    ;
    ;
  };
  while (abs(ok - ng) > 1) {
    int mid = (ng + ok) / 2;
    if (solve(mid))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}