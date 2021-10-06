// Test driver
#include <iostream>
#include <fstream>

#include "StackTType.h"

using namespace std;

// return 값을 저장하지 않으면 사라짐. return by value니깐.
// class에서 return *this나, 다른 attribute return 하는 것은 사라지지 않음. 
// reference로 인자로 받고 받은 것을 return 하면 되지 않나?? 그게 overhead가 적을 듯?
template<typename T>
void Copy(const StackType<T>& copied, StackType<T>& copier)
{
	StackType<T> dumy{ copied };
	StackType<T> inverse_dumy{};

	// to copy stack, make temporal inverse stack
	while (!dumy.IsEmpty())
	{
		inverse_dumy.Push(dumy.Top());
		dumy.Pop();
	}

	// 
	while (!inverse_dumy.IsEmpty())
	{
		copier.Push(inverse_dumy.Top());
		inverse_dumy.Pop();
	}

}

template<typename T>
void PrintStack(StackType<T> elem)
{
	while(!elem.IsEmpty())
	{
		cout << elem.Top() << endl;
		elem.Pop();
	}

}



int main()
{
	StackType<int> stack1;
	for (int i = 0; i < 5; i++)
		stack1.Push(i);

	StackType<int> stack2;
	for (int i = 5; i > 0; i--)
		stack2.Push(i);

	StackType<int> stack3;

	Copy<int>(stack2, stack3);
	PrintStack(stack3);



  //ifstream inFile;       // file containing operations
  //ofstream outFile;      // file containing output
  //string inFileName;     // input file external name
  //string outFileName;    // output file external name
  //string outputLabel;     
  //string command;        // operation to be executed
  //
  //int item;
  //StackType<int> stack;
  //int numCommands;


  //// Prompt for file names, read file names, and prepare files
  //cout << "Enter name of input command file; press return." << endl;
  //cin  >> inFileName;
  //inFile.open(inFileName.c_str());

  //cout << "Enter name of output file; press return." << endl;
  //cin  >> outFileName;
  //outFile.open(outFileName.c_str());

  //cout << "Enter name of test run; press return." << endl;
  //cin  >> outputLabel;
  //outFile << outputLabel << endl;

  //inFile >> command;


  //numCommands = 0;
  //while (command != "Quit")
  //{ 
  //  try 
  //  {
  //    if (command == "Push")
  //    {
  //      inFile >> item; 
  //      stack.Push(item);
  //    }
  //    else if (command == "Pop")
  //      stack.Pop();
  //    else if (command == "Top")
  //    {
  //      item = stack.Top(); 
  //      outFile<< "Top element is " << item << endl;
  //    } 
  //    else if (command == "IsEmpty") 
  //      if (stack.IsEmpty())
  //        outFile << "Stack is empty." << endl;
  //      else 
  //        outFile << "Stack is not empty." << endl;
  //           
  //    else if (command == "IsFull")
  //      if (stack.IsFull())
  //        outFile << "Stack is full." << endl;
  //      else outFile << "Stack is not full."  << endl;  
  //  }
  //  catch (FullStack)
  //  {
  //    outFile << "FullStack exception thrown." << endl;
  //  }
  //  
  //  catch (EmptyStack)
  //  {
  //    outFile << "EmtpyStack exception thrown." << endl;
  //  }    
  //  numCommands++;
  //  cout <<  " Command number " << numCommands << " completed." 
  //       << endl;
  //  inFile >> command;
 
  //};
 
  //cout << "Testing completed."  << endl;
  //inFile.close();
  //outFile.close();
  //return 0;
}


