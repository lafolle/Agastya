/*

  Simple implementation of a Trie.

  Highly restricted. Alphabet being [a-z]
  
  Time-stamp: <2012-10-09 19:04:08 kc>
*/


#include <vector>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

class Node{
public:
  char ch;
  Node *father;
  Node *children[26];
  Node(char c,Node *f){
    ch=c;
    father=f;
    int i;
    for(i=0;i<26;i++)this->children[i]=NULL;
  }
};

Node root('\0',NULL);

// checks membership of word in trie
bool present(const string &word)
{
  Node *node = &root;
  int i, wl=word.length();
  for(i=0;i<wl && node;i++) node=(*node).children[word[i]-'a'];
  return i==wl;
}


// inserts word in trie
void insert(const string &word, int pos, Node &node)
{
  if(word.length()==pos) return;
  Node *nptr,*newnode;
  nptr = node.children[word[pos]-'a'];
  if(!nptr){
    newnode = new Node(word[pos],&node);    
    node.children[word[pos]-'a']=newnode;
    insert(word, pos+1, *newnode);
  }
  else insert(word, pos+1, *nptr);
}

int main()
{
  // one infite loop
  while(1){
    char word[30];    
    scanf("%s", word);
    string w(word);
    if(present(w))
      printf("%s present in trie.\n",word);
    else{
      insert(w, 0, root);
      printf("%s is pushed in trie.\n",word);      
    }
  }

  return 0;
}
