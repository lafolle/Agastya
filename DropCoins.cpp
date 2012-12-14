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

using namespace std;

class DropCoins {
public:
	int getMinimum(vector <string>, int);
};

int get_min(int a, int b, int c, int d)
{
	vector<int> x(4);
	x[0]=2*(a+b)+c+d;x[1]=2*(b+c)+a+d;
	x[2]=2*(c+d)+a+b;x[3]=2*(d+a)+b+c;

	return *min_element(x.begin(),x.end());
}

int DropCoins::getMinimum(vector <string> board, int K) {
	int h=board.size(),w=board[0].size(),i,j,k,min_cost=1000000;
	int count,a,b,c,d,l,m,n;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			
			for(k=i+1;k<h;k++){
				for(l=j+1;l<w;l++){
					count=0;
					for(m=i;m<k+1;m++){
						for(n=j;n<l+1;n++)
							if(board[m][n]=='o')
								count+=1;
					}
					if(count==K){
						a=i+1;b=w-l+1;
						c=j+1;d=j+1;
						min_cost=std::min(min_cost, get_min(a,b,c,d));
					}
				}
			}
		}
	}
}


//Powered by [KawigiEdit] 2.0!
