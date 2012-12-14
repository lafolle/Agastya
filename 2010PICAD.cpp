#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <string>
#include <numeric>
#include <set>
#include <cstdio>

using namespace std;

typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef vector<vector<int> > vvi;

#define pl printf("\n")
#define all(c) c.begin(), c.end()
#define ARRIVAL 0
#define DEPARTURE 1

int p, k;
int c;

void getinput(vpii &event)
{
    scanf("%d %d", &p, &k); // Get crime interval
    int i, j, people;
    c = 0;
    scanf("%d", &people); // Has to be more than equal to 3
    for(i=0; i<people; i++){
        pii interval;
        scanf("%d %d", &interval.first, &interval.second);
        if(interval.first>k || interval.second<p) continue;
        ++c;
        event.push_back(make_pair(interval.first, ARRIVAL));
        event.push_back(make_pair(interval.second, DEPARTURE));
    }
}

pii getminmax(const vpii &event)
{
    //If all intervals are invalid
    if(!c) return(make_pair(0, 0)); 
    int minp, maxp, i, j, t;
    int instCount = 0; // At any instant number of people present

    i=0;

    while(event[i].first <= p && event[i].second != DEPARTURE){ 
        ++instCount;
        ++i;
    }
    minp = maxp = instCount;
    int m = event[i].first;
    int l = 0;
    int limit = 2*c; //Just precomputing
    for(j=i; j<limit && event[j].first<=k; j++){
        // Seeing before a point
        if(m != event[j].first){ 
            instCount -= l;
            minp = min(minp, instCount);
            l = 0;
        }
        // Seeing at a point
        if(event[j].second == ARRIVAL)
            ++instCount;
        else // or departure
            ++l;
        maxp = max(maxp, instCount);
        m = event[j].first; //Remembering time event
    }
    return make_pair(minp, maxp);
}

int main()
{
    int t=0;

    while(t++<10){ // 10 test cases follow
        pii pa;
        vpii event;

        getinput(event);
        sort(all(event));
        pa = getminmax(event);

        printf("%d %d\n", pa.first, pa.second);
    }
    return 0;
}

