// This module explain r-value reference in C++11.
// Also explane const return 

#include <iostream>

const int* returning_pointer()
{
    int local_var = 1;
    return &local_var;
}

int function(int const const_parapm)
{
    int adws = 9;
    std::cout << adws;
    return 5;
}

int main()
{
    //int return_value = function(5);

    //return_value = 4;
    const int* p_var = returning_pointer();
    // *p_var = 5; const라서 바꿀 수는 없다. 그런데 궂이 pointer를 return해서 써야하는가?
    // malloc같은 것을 return해주는 interface면 필요할 것 같다.
    std::cout << *p_var+1 << std::endl;
    //std::cout << return_value;
    return 0;
}