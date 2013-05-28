#include <iostream>

using namespace std;

int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	while(n or m or c){
	  cout << (c ? (m*n)/64 : ((m-1)*n)/64) << endl;
	  cin>>n>>m>>c;
	}
	
	return 0;
}

// BUllshit explanation
