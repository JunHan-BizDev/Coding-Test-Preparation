
def quickSort(low, high, list):
    if(high - low < 1):
        return
    else:
        pivot = partition(low, high,list)
        quickSort(low, pivot - 1,list)
        quickSort(pivot + 1, high,list)

def partition(low, high, list):
    reference = low
    location = low
    for idx in range(low+1, high):
        if(list[idx] < list[reference]):
            location += 1
            list[idx], list[location] = list[location], list[idx]

    list[reference], list[location] = list[location], list[reference]
    return location

def prod2(x, y):

    upper_x, upper_y , lower_x,  lower_y = 0
    digit, small_digit = 0
    mult1, mult2, mult3 = 0

    digit = max(len(x), len(y))
    if x == 0 or y == 0:
        return
    elif digit <= 4:
        return x * y
    else:
        small_digit = digit // 2
        upper_x = x // pow(10,small_digit)
        upper_y = y // pow(10,small_digit)
        lower_x = x % pow(10,small_digit)
        lower_y = y % pow(10,small_digit)

        mult1 = prod2(upper_x + upper_y, lower_x + lower_y)
        mult2 = prod2(upper_x, lower_x)
        mult3 = prod2(upper_y, lower_y)

        return mult2 * pow(10, 2*small_digit) + ((mult1 - mult2 - mult3) * pow(10, small_digit) + mult3)
