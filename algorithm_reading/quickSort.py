# 快排
def quickSort(arr):
    if len(arr) < 2:
        return arr
    else:
        temp = arr[0]
        less = [i for i in arr[1:] if i <= temp]
        greater = [i for i in arr[1:] if i > temp]
        return quickSort(less) + [temp] + quickSort(greater)


print(quickSort([5, 4, 6, 54, 8, 9, 10]))
