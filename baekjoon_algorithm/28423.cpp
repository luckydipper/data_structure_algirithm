//stio 
//dp이다.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

vector<int> parse(int i) {
  vector<int> ret;
  while (i > 0) {
    ret.push_back(i % 10);
    i /= 10;
  }
  return ret;
}
int summation(vector<int> vec){
    int ret = 0;
    for(int i = 0; i < vec.size(); i++)
        ret += vec[i];
    return ret;
}
int mult(vector<int> vec){
    int ret = 1;
    for(int i = 0; i <vec.size(); i++)
        ret *= vec[i];
    return ret;
}

int concat(int i, int j) {
    string pre = to_string(i);
    string post = to_string(j);
    string concat = pre+post;
    return stoi(concat);
}
int cache[100001];// -10 not visit, -5 is visited 

int f(int i) {
  vector<int> a = parse(i);
  int i_prime = concat(summation(a), mult(a));
  if (i > 100000 || i_prime > 100000)
    return cache[i] = -1;
  if(cache[i] == 1 || cache[i] == -1)
    return cache[i];
  if(cache[i] == -5)
    return cache[i] = 0;

  if(i == i_prime){
    return cache[i] = cache[i_prime] = 1;
  }
  else{
    cache[i] = -5;
    return cache[i] = f(i_prime);
  }
}
int L, R;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> L >> R;
  for(int i = 0; i < 100001; i++)
    cache[i] = -10;
  int ret = 0;
  for (int i = L; i <= R; i++)
    ret += f(i);

  cout << ret;
}