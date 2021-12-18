def bitCount(x):
    count = 0
    base = 0x10
    for i in range(5):
        if x % pow(2,i) != 0 :#가
            count += 1
        pass    
    return count
 

if __name__ == "__main__":
    a = 0x1C
    b = 0x15
    c = a & b
    print(bitCount(c))