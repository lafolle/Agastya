
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

int DropCoins::getMinimum(vector <string> board, int K) {
	int h=board.size(),w=board[0].size(),i,j,k,min_cost=1000000;
	int count,a,b,c,d,l,m,n;
	
	for(i=0;i<h-1;i++){
		for(j=0;j<w-1;j++){
			
			for(k=i+1;k<h;k++){
				for(l=j+1;l<w;l++){
					count=0;
					for(m=i;m<k+1;m++){
						for(n=j;n<l+1;n++)
							if(board[m][n]=='o')
								count+=1;
					}
					if(count==K){
						a=j;
						b=w-l;
						c=i;
						d=h-k;
						int p=a+b+c+d+min(a,b)+min(c,d);
						cout<<p<<endl;
						min_cost=std::min(min_cost, p);
					}
				}
			}
		}
	}
	return min_cost==1000000?-1:min_cost;
}


//Powered by [KawigiEdit] 2.0!<%:testing-code%>



double test0() {
	string t0[] = {".o.."
,"oooo"
,"..o."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"...."
,".oo."
,".oo."
,"...."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 58;
	DropCoins * obj = new DropCoins();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

