
def quickSort(low, high, list):
    if(high - low < 1): # base case 설정
        return
    else:
        pivot = partition(low, high,list) #pivot point 반환
        quickSort(low, pivot,list)
        quickSort(pivot + 1, high,list)

def partition(low, high, list):
    reference = low # 대상이 되는 변수
    location = low
    #reference index 변수 기준으로 크기별로 좌,우 분할
    for idx in range(low+1, high):
        if(list[idx] < list[reference]):
            location += 1
            list[idx], list[location] = list[location], list[idx]

    #분할 후 reference index value와 분할 기준 index value랑 바꿔주기
    list[reference], list[location] = list[location], list[reference]

    return location

#큰 정수곱셈(빠른 버전)
def prod2(x, y):


    digit = max(len(str(x)), len(str(y)))
    if x == 0 or y == 0:
        return 0
    elif digit <= 4:
        return x * y
    else:
        small_digit = digit // 2
        upper_x = x // pow(10,small_digit)
        upper_y = y // pow(10,small_digit)
        lower_x = x % pow(10,small_digit)
        lower_y = y % pow(10,small_digit)

        mult1 = prod2(upper_x + lower_x, upper_y + lower_y)
        mult2 = prod2(upper_x, upper_y)
        mult3 = prod2(lower_x, lower_y)

        return mult2 * pow(10, 2 * small_digit) + (mult1 - mult2 - mult3) * pow(10, small_digit) + mult3

list = [3,5,2,9,10,14,4,8,1,17,0]
print("-- Quick sort --\nBefore quick sort : ")
print(list)

quickSort(0,len(list),list)

print("After quick sort : ")
print(list)

print("\n-- Big Integer multiplication -- ")

a = 1234567812345678
b = 2345678923456789
print("Using Prod2 function : " + str(prod2(a,b)))
print("Typical caculation   : " + str(a * b))
