// 2022/10/01
// tip1 : 처음에 n번 반복한다고 하면, 그래로 반복한다. stack이 비워질 때 까지 반복한다고 하면 실수가 많음!
// tip2 : print string에 \n 1개씩 넣지 말고, 문자열만 넣은 후, \n 첨가해서 출력!

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	
	stack<int> stack_;
	string print_data;
	
	int start_to_push = 1;
	while(n--)
	{
		int search_data;
		cin >> search_data;
		
		if(stack_.empty() || stack_.top() < search_data)
		{
			for (int i = start_to_push; i <= search_data; i++)
			{
				stack_.push(i);
				print_data += "+\n";
			}
			start_to_push = stack_.top() + 1;
			stack_.pop();
			print_data += "-\n";
		}
		else if(stack_.top() == search_data)
		{
			
			stack_.pop();
			print_data += "-\n";
		}
		else
		{
			print_data = "NO";
			break;
		}
	}
	cout << print_data;
}