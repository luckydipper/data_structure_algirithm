#include "turn_by_reference_const_type.hpp"
#include <iostream>
#include <string>

int wmain(int argc, char* argv[])
{
    int a = 1, b = 2;
    int c = a + b;
    Point p1(1, 2);
    Point p2(0, 1);
    //(p1 + p2)++;// ++가 const method가 아니기 때문에 불가능 함.
    
    
    // 복사 생성자를 호출해?
    (p1 + p2).get_point();
    // p1.operator+(p2)
    // debug mode로 호출할 시, 한개씩 호출하다보니 복사 생성자도 호출함.
    // release로 compile하니 정상 작동함.


    std::wstring some_contex = L"Some Unicode 한글 같이";
    std::wcout << some_contex << std::endl;
    std::cout << argc << std::endl;
    std::cout << argv << std::endl;

}