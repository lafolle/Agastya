#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<map>

using namespace std;
int cc;
int find_sib(string name , multimap<string,string>& s , int curr_level , int level)
{   

   vector<string> scope;
   pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret = s.equal_range(name);

   if(s.count(name)>0)
   for (multimap<string,string>::iterator it = ret.first ; it != ret.second ; it++ )   
   { 
      scope.push_back(it->second);   
   }   
   
   if(curr_level >= level || scope.size()==0)
             return scope.size();
                              
   else
   {
      int sum = 0;
      for (int j = 0 ; j < scope.size() ; j++)
      {
         sum = sum +  find_sib( scope[j] , s , curr_level+1 , level );
      }
      return sum;
   }      
}

bool myfunction (pair<int,string>i , pair<int,string>j ) 
{ 
   if (i.first < j.first)
      return true;
   else if (i.first == j.first)
   {
      if (i.second > j.second)
         return true;
      else   
         return false;
   }
   else
      return false; 
}


int main()
{

int Kases,n,l,no,ss;   

multimap<string,string> s;

set< pair<int,string> >bottom;   
multimap<string,string>::iterator ak; 
vector< pair<int,string> >::reverse_iterator itn;
set< pair<int,string> >::iterator iit;
vector< pair<int,string> >::iterator itnb,itnbstart;
vector< pair<int,string> >answer;

pair<int , string> pi;
string parent,child;
pair<string , string> ps;
vector<string> memo;

   cin >> Kases;

for(int i = 1 ; i <= Kases ; i++)
{

cout << "Tree "<<i<<":"<<endl ;
         
      s.clear();
      answer.clear();
      bottom.clear();
      memo.clear();            
      cin >> n >> l;
      while(n--)
      {
         cin >> parent >> no;
         while(no--)
         {
            cin >> child;
            s.insert (pair<string,string>(parent,child));
         }   
      }
   
   for(ak = s.begin() ; ak != s.end() ; ++ak)
   {
      if (find(memo.begin() , memo.end() , ak->first) == memo.end())
      {   

         int value =   find_sib(ak->first , s , 1 , l);
         pi = make_pair(value,ak->first);
         answer.push_back(pi);      
      }
      memo.push_back(ak->first);
   }   

   sort(answer.begin() , answer.end() , myfunction);            
   bool nothing = true;                          
   int cc = 0;   
   if( l == 0)
   {
      for (itn = answer.rbegin() ; itn != answer.rend() ; itn++)
      {
         if (cc < 3)
         {       cc++;
            cout << itn->second<<" "<<"1\n";
         }
         else
            break;   
      }
      if (i<Kases)cout << endl;
      continue;
      
   }
   
   for(itnb = answer.begin() ; itnb != answer.end() ; itnb++)
   {
         
      if(itnb->first != 0)
      {
         nothing = false;
         itnbstart=itnb;
         break;
      }
   }
   if (nothing == true){if(i < Kases)cout << endl;continue;}

   for(itnb = itnbstart ; itnb != answer.end() ; itnb++)      
   {
      if(itnbstart->first == itnb->first)
      {   
         pi = make_pair(itnb->first,itnb->second);         
         bottom.insert(pi);
      }      
      else
         break;
   }
                        
  bool zero=false,bot=false;
   int count = 0;
   for(itn = answer.rbegin() ; itn != answer.rend() ; itn++)      
   {
      if(count < 3 && itn->first != 0  && itn->first != itnbstart->first )
      {
         cout << itn->second << " " << itn->first<<endl; 
         count++;

                        
      }
            
      if(itn->first == itnbstart->first )
      {   
         bot = true;
         break;
      }
   }

   if (count < 3 && bot==true)
   {
      for(iit = bottom.begin() ; iit != bottom.end() ; ++iit)
      {
         cout << iit->second << " " << iit->first<<endl;
      }   
   }      
   if(i<Kases)cout << endl;         
   
}   
}
