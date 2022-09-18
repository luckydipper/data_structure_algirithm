#include <iostream>
#include <string>

class Stack
{
private:
	int max_size;
	int current_size = -1;
	int* buffer;
	
public:
	explicit Stack(int size);
	~Stack();
	void Push(int val);
	int Pop();
	int Size();
	int IsEmpty();
	int Top();
};

Stack::Stack(int size): max_size(size)
{
	buffer = new int(max_size);
}
Stack::~Stack()
{
	delete buffer;
}
void Stack::Push(int val)
{
	current_size++;
	buffer[current_size] = val;
}
int Stack::Pop()
{
	current_size--;
	return buffer[current_size+1];
}
int Stack::Size()
{
	return current_size + 1;
}
int Stack::IsEmpty()
{
	std::cout << current_size << "\n";
	if (current_size == -1)
		return 1;
	else
		return 0;
}
int Stack::Top()
{
	if(current_size == -1)
		return -1;
	else
		return buffer[current_size];
}

int main()
{
	int stack_size;
	std::cin >> stack_size;
	Stack test_stack(stack_size);
	
	std::string pop("pop"), push("push"), top("top"), size("size"), empty("empty");
	while(true)
	{
		std::string command;
		std::cin >> command;
		
		if (command == push)
		{
			int val;
			std::cin >> val;
			test_stack.Push(val);
		}
		else if(command == pop)
		{
			std::cout << test_stack.Pop() << "\n";
			if(test_stack.Size() == 0)
				std::cout << "-1\n";
		}
		else if(command == top)
			std::cout << test_stack.Top() << "\n";
		else if(command == size)
			std::cout << test_stack.Size() << "\n";
		else if(command == empty)
			std::cout << test_stack.IsEmpty() << "\n";
		else
			break;
	}

}
