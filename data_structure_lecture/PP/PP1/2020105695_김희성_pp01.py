
class Matrix:
    def __init__(self, first_:int, second_:int, third_:int, fourth_:int) -> None:
        self.first = first_
        self.second = second_
        self.third = third_
        self.fourth = fourth_

    def print_matrix(self)->None:
        print(f"[{self.first}, {self.second}, {self.third}, {self.fourth} ]")
    
    def __str__(self) -> str:
        return f"{self.first}, {self.second} \n{self.third}, {self.fourth} \n"

    def __add__(self, operand):
        return Matrix(  self.first  + operand.first,
                        self.second + operand.second,
                        self.third  + operand.third,
                        self.fourth + operand.fourth)
    
    def __sub__(self, operand):
        return Matrix(  self.first  - operand.first,
                        self.second - operand.second,
                        self.third  - operand.third,
                        self.fourth - operand.fourth)


if(__name__ == "__main__"):
    print("--- test start ---")
    A  = Matrix(1, 2, 3, 4)  
    B = Matrix(5, 6, 7, 8) 
    C = A+B 
    D = A-B  
    print(C) 
    print(D)
    print("--- test end ---")