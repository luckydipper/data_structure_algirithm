#include "turn_by_reference_const_type.hpp"


int main()
{
    Point p1(1, 2);
    Point p2(0, 1);
    //(p1 + p2)++;// ++가 const method가 아니기 때문에 불가능 함.
    
    
    // 복사 생성자를 호출해?
    (p1 + p2).get_point();
    // p1.operator+(p2)
    // debug mode로 호출할 시, 한개씩 호출하다보니 복사 생성자도 호출함.
    // release로 compile하니 정상 작동함.
}