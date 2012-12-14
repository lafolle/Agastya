

// 15. The Shortest Path (SHPATH)

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <cassert>

using namespace std;

static const int CITY_NUM = 10000;
static const int NAME_LEN = 11;

struct KeyComp {
   bool operator() (char * const & lhs, char * const & rhs) const {
      return strcmp(lhs, rhs) < 0;
   }
};

char cityName[CITY_NUM][NAME_LEN];
int  cityCount;
int  minCost[CITY_NUM];
map<char *, int, KeyComp> m;

struct City {
   vector<int> path;   // connect to city #
   vector<int> cost;   // the cost for travelling
   int pathCount;        // number of paths
   int index;            // index to the name of this city

   void read(int index) {
      this->index = index;
      scanf("%d", &pathCount);
      path.clear();
      cost.clear();
      path.reserve(pathCount);
      cost.reserve(pathCount);
      for (int i = 0; i < pathCount; ++i) {
         int aPath, aCost;
         scanf("%d %d", &aPath, &aCost);
         path.push_back(aPath - 1);   // index is 1-based
         cost.push_back(aCost);
      }
   }
};

struct QComp {
   bool operator() (int const & lhs, int const & rhs) const {
      return minCost[lhs] > minCost[rhs];
   }
};

City city[CITY_NUM];

void readCase() {
   scanf("%d", &cityCount);
   for (int i = 0; i < cityCount; ++i) {
      scanf("%s", cityName[i]);
      m[cityName[i]] = i;
      city[i].read(i);
   }
}

int getCost(int from, int to) {
   bool visited[CITY_NUM];

   // make the cost to from = 0 and all others infinity
   // mark all cities as unvisited
   for (int i = 0; i < cityCount; ++i) {
      visited[i] = false;
      minCost[i] = INT_MAX;
   }
   minCost[from] = 0;

   priority_queue<int, vector<int>, QComp> pq;
   assert(pq.empty());
   pq.push(from);
int lst = 0;
   while (!pq.empty()) {
      int current = pq.top();
      pq.pop();
      assert(minCost[current] >= lst);
      lst = minCost[current];
      if (visited[current]) continue;
      visited[current] = true;

      City & c = city[current];
      for (int i = 0; i < c.pathCount; ++i) {
         int dst = c.path[i];
         int costViaCurrent = minCost[current] + c.cost[i];
         if (costViaCurrent < minCost[dst]) {
            minCost[dst] = costViaCurrent;
            pq.push(dst);
         }
      }
      if (current == to) break;
   }
   return minCost[to];   
}

void doCase() {
   int count;
   scanf("%d", &count);
   while (count--) {
      char from[NAME_LEN], to[NAME_LEN];
      scanf("%s %s", from , to);
      printf("%d\n", getCost(m[from], m[to]));
   }
}

int main() {
   int count;
   scanf("%d", &count);
   while (count--) {
      m.clear();
      readCase();
      doCase();
   }
}
