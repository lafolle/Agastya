#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int rows[1234];
    int cols[5678];
    for (int i=0; i<1234; i++) rows[i]=i;
    for (int j=0; j<5678; j++) cols[j]=j;
    char c;
    int x,y,temp,z,i;
    while (!cin.eof()) {
        cin >> c;
        switch (c) {
            case 'R':
            cin >> x >> y;
            temp = rows[x-1];
            rows[x-1]=rows[y-1];
            rows[y-1]=temp;
            break;
            case 'C':
            cin >> x >> y;
            temp = cols[x-1];
            cols[x-1]=cols[y-1];
            cols[y-1]=temp;
            break;
            case 'Q':
            cin >> x >> y;
            // original position is rows[x-1], cols[y-1]
            printf("%d\n",rows[x-1]*5678+cols[y-1]+1);
            break;
            case 'W':
            cin >> z;
            // original position is (z-1)/5678, (z-1)%5678
            x=(z-1)/5678;
            y=(z-1)%5678;
            for (i=0; i<1234; i++) {
                if (rows[i]==x) printf("%d ",i+1);
            }
            for (i=0; i<5678; i++) {
                if (cols[i]==y) printf("%d\n",i+1);
            }
            break;
        }
    }
}
