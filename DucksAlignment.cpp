#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef vector<int> vi;

using namespace std;

class DucksAlignment {
public:
	int minimumTime(vector <string>);
};

int DucksAlignment::minimumTime(vector <string> grid) {
	int m=grid.size(), n=grid[0].size(),i,j,k,c=0;
	vi ox,oy;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(grid[i][j]=='o'){
				ox.push_back(i);
				oy.push_back(j);
				++c;
			}
	
	int min_cost=1000,cost_r=0,cost_c=0,r,c;
	for(i=0;i<c;i++){
		// check for row
		cost_x=0;
		cost_c=0;
		for(j=0;j<c;j++){
			cost_x+=abs(ox[j]-ox[i]);
			cost_c+=abd(ox[j]-oy[i]);
		}
		min_cost = min(min_cost, min(cost_r,cost_c));	
	}
	return min_cost;			
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
