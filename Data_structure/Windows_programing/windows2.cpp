#include <iostream>
#include <Windows.h>



int StackPointerResgister();
int StackPointer2();



DWORD WINAPI ThreadProcess(LPVOID lpParam)
{
    DWORD threadNum = (DWORD)lpParam;

}

// _tmain은 wmain과 main을 섞어서 호환하여 사용하기 위해, 마소가 만든 것.
// ANCI에서 만든 c++에는 추가되있지 않아.
int main(int argc, char* argv[])
{
    int student_score[30] = { 0 };
    int first{ 0 };
    int second{ 1 };
    

    // 이럴바에는 element 기반 for를 쓰지 말자.
    // index는 안에 넣는게 좋다.
    // auto는 괜찮은 아이디어다.
    // 안의 data자료를 바꿔도 변경 가능.
    //int index = 0;
    //for (auto &score : student_score)
    //    score = index++;

    //// print score
    //for (auto const score : student_score)
    //    std::cout << score << std::endl;

    //// process handle은 structure 이므로 structure의 맨 앞을 가르키는 pointer가 출력됨
    //HANDLE current_handle{ GetCurrentProcess() };
    //std::cout << current_handle;    


    StackPointerResgister();
    
    return 0;
};



int StackPointer2()
{
    std::cout << "StackPointer2 is called\n";
    return 0;
}

int StackPointerResgister()
{
    int a = 1;
    std::cout << "stack1 Pointer called\n";
    StackPointer2();
    return 0;
}
