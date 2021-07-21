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
    int return_value = function(5);

    return_value = 4;
    const int* p_var = returning_pointer();
    std::cout << p_var << std::endl;
    std::cout << return_value;
    return 0;
}