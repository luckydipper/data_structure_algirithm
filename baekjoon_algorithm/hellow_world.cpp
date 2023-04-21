#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, string from, string to, string by){
	if(n == 1){
		cout << "move " << from << " -> " << to <<" \n";
		return;
	}hanoi(n-1,from,by,to);
	hanoi(1,from,to,by);
	hanoi(n-1,by, to, from);
}

int main(int argc, char** argv)
{
	hanoi(3,"A","B","C");
}