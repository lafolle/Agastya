#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){

  int c=0;
  string s = "098m03r9f80239802389f0m9KDKLKLJDKLJm0983m890DMOm03";
  vector<string> res;
  char buff[1024];
  strcpy(buff, s.c_str());
  for(char *word = strtok(buff, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ., ");
      word;
      word=strtok(NULL, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ., "), c++)
    res.push_back(string(word));

  int n=c;
  if(c%2!=0) n=(c+1)/2;

  // process first n stringed numbers in res

  return 0;
}
