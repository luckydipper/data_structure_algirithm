// This module explain r-value reference in C++11.
// Also explane const return 

#include <iostream>


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
    std::cout << return_value;
    return 0;
}