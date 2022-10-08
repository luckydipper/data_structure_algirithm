// io는 python이 유리하다.
// 하지만 성능 측면에서 c++ string STL을 알아두도록 하자.
#include <iostream>
#include <string>
using namespace std;

int main1()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string origin_string;
	cin >> origin_string;
	
	int N;
	cin >> N;
	
	int cusor_position = origin_string.length();
	
	for(int i = 0; i < N; i++)
	{
		string instruction;
		cin >> instruction;
		
		if(instruction == "L")
		{
			if(cusor_position == 0)
				continue;
			cusor_position--;
		}
		else if(instruction == "D")
		{
			if(cusor_position == origin_string.length())
				continue;
			cusor_position++;
		}
		else if(instruction == "B")
		{
			if(cusor_position == 0)
				continue;
			origin_string.erase(--cusor_position, 1);	
		}
		else if(instruction == "P")
		{
			cin >> instruction;
			origin_string.insert(cusor_position, instruction);
			cusor_position += instruction.length();
		}
	}
	cout << origin_string;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string origin_string;
	cin >> origin_string;
	
	int N;
	cin >> N;
	
	int cusor_position = origin_string.length();
	
	char s[100001];

}