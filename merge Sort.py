## 두 방법이 존재
## 1. array dividing할때 array 사용 --> 공간복잡도 2n
## 2. array index를 이용한 divide & conceur
     #이때 merging 단계에서 new array들이 사용 --> 공간 복잡도 : n 

def merge_sort1(arr):
    arr_len = []
    size_cal = []
    total_size = 0
    final = []
    def merge(low_arr, high_arr, size_cal):
        merged_arr = []

        l = h = 0
        while l < len(low_arr) and h < len(high_arr):
            if low_arr[l] < high_arr[h]:
                merged_arr.append(low_arr[l])
                l += 1
            else:
                merged_arr.append(high_arr[h])
                h += 1
        merged_arr += low_arr[l:]
        merged_arr += high_arr[h:]
        
        return merged_arr



    def mergeSort(arr,size_cal, arr_len):
    
        if len(arr) < 2:
            return arr
        
        mid = len(arr) // 2
        arr_len.append(len(arr))
        low_arr = mergeSort(arr[:mid], size_cal,arr_len)
        size_cal.append(len(low_arr))
        high_arr = mergeSort(arr[mid:], size_cal,arr_len)
        size_cal.append(len(high_arr))

        
        return merge(low_arr, high_arr, size_cal)

        
    final = mergeSort(arr,size_cal, arr_len)
    size_cal_set = set(size_cal)
    for elem in size_cal_set:
        total_size += elem * 2
    print("NEEDED SPACE : " + str(total_size))
    
    return final


## mergesort using index

def merge_sort2(arr):
    size_cal = []
    total_size = 0
    final = []

    def mergeSort2(low, high, size_cal):
        if high - low < 2:
            return
        mid = (high + low) // 2
        mergeSort2(low,mid, size_cal)
        mergeSort2(mid,high, size_cal)
        
        merge2(low,mid,high, size_cal)
        
    def merge2(low, mid, high, size_cal):
        temp_arr = []
        i, j = low, mid
        
        if(len(size_cal) > 0):
            del size_cal[-1]
        
        while i < mid and j < high:
            if arr[i] < arr[j]:
                temp_arr.append(arr[i])
                i += 1
            else:
                temp_arr.append(arr[j])
                j += 1
            
        while i < mid:
            temp_arr.append(arr[i])
            i += 1
        while j < high:
            temp_arr.append(arr[j])
            j += 1
        
        for idx in range(low, high):
            arr[idx] = temp_arr[idx - low]
        
        size_cal.append(len(temp_arr))
    
    final =  mergeSort2(0, len(arr), size_cal)
    
    total_size = size_cal[-1]
    print("NEEDED SPACE : " + str(total_size))


        
list_ = [3,16,13,1 ,9,2,7,5, 8,4,11,6, 15,14,10,12]

print("before mergeSort1 : ")
print(list_)
print("\nafter mergeSort1 : ")
print(merge_sort1(list_))



list_ = [3,16,13,1 ,9,2,7,5, 8,4,11,6, 15,14,10,12]
print("\n\nbefore mergeSort2 : ")
print(list_)
print("\nafter mergeSort2 : ")
merge_sort2(list_)
print(list_)


