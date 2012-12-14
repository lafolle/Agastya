//Wednesday 16 December 2009 08:04:13 PM IST
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
 
#define MAX_TIME 1000000
using namespace std;

int w, h;
char shop[25][25];
int visited[25][25];
int d[25][25];
const int neigh[4][2] = {1,0, 0,1, -1,0, 0,-1};

class Node{
    public:
        int r;
        int c;
        Node() : r(0), c(0){}
        bool operator<(const Node &n) const
        {
            return d[this->r][this->c] > d[n.r][n.c];  // Hack, untill i'll know howto use priority_queue
        }
};

Node src; // Source node

void relax(const int i, const int j, const int m, const int n)
{
    if(d[m][n] > d[i][j] + shop[m][n] - '0'){
        if(shop[m][n] == 'D')
            d[m][n] = d[i][j];
        else
            d[m][n] = d[i][j] + shop[m][n] - '0';
    }
}

bool valid(const int i, const int j)
{
    return i>=0 && i<h && j>=0 && j<w;
}

/*
 * Dijkstra
 */
int min_sec()
{
    Node tmp, current_node;
    int i;
    d[src.r][src.c] = 0;

    priority_queue<Node> pq;
    pq.push(src);

    while(pq.empty() == false){
        current_node = pq.top();
        pq.pop();

	// check for destination reached.
        if(shop[current_node.r][current_node.c] == 'D')
            break;

        visited[current_node.r][current_node.c] = true;

        for(i=0; i<4; i++){
            tmp.r = current_node.r + neigh[i][0];
            tmp.c = current_node.c + neigh[i][1];
	        if(valid(tmp.r, tmp.c) && shop[tmp.r][tmp.c] != 'X' && !visited[tmp.r][tmp.c]){
	            relax(current_node.r, current_node.c, tmp.r, tmp.c);
	            pq.push(tmp);
            }
        }
    }
    return d[current_node.r][current_node.c];
}

void setup()
{
    int i=0, j=0;
    for(i=0; i<h; i++)
        scanf("%s", shop[i]);
    fflush(stdin);
    // Want to use memset, but ignorance
    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            if(shop[i][j] == 'S'){
                src.r = i;
                src.c = j;
            }
            visited[i][j] = false;
            d[i][j] = MAX_TIME;
        }
    }
}

int main()
{
    int i, row = 0;
    int min_time;

    scanf("%d %d", &w, &h);
    while(w != 0 && h != 0){
        setup();
        min_time = min_sec();
        printf("%d\n", min_time);

        scanf("%d %d", &w, &h);
    }
    return 0;
}

