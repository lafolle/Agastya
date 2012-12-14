/*Comment(s):
1.
G.size() is the number of nodes in the graph. G[i][j].first is
the jth node that can be reached from node 'i'. G[i][j].second is the distance
from node 'i' to the node described by G[i][j].first,

2.
ii is a pair<int,int>
vvii is vector<vector<pair<int,int> > >
vi is vector<int>
INF is INT_MAX
*/

void dijkstra(int start,int end, vvii&G)//start city, end city, graph
{
   vi D(G.size(),INF);//initial distance of each city to the start city
   set<ii> Q;// <city #, distance>
   D[start]=0;//set start city distance to itself to 0
   Q.insert(ii(start,0));//add that city to the "queue" 
   while(!Q.empty())
   {
      ii top=*Q.begin();
      Q.erase(Q.begin());
      int v=top.first, d=top.second;
      tr(G[v],it)//search through all cities connected to city v
      {
         int v2=(*it).first, cost=(*it).second;
         if(D[v2]>D[v]+cost)//if less expensive
         {
            if(D[v2]!=INF)//remove from set because we have found a better solution
               Q.erase(Q.find(ii(v2,D[v2])));
            D[v2]=D[v]+cost;//update distance list
            Q.insert(ii(v2,D[v2]));//add this new city and its distance to
            //start city to the set
         }
      }
   }
   printf("%d\n",D[end]);//print out the shortest distance to the ending city
}   
