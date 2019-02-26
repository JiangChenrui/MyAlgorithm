# 选择排序
def findSmallest(arr):
    smallest = arr[0]
    smallest_index = 0
    for i in range(len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index


def selectionSort(arr):
    """
    每次循环选择最小值，然后将其输入新数组中，这种方式会将原数组清空
    """
    newArr = []
    for i in range(len(arr)):
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    return newArr


def selectionSort2(arr):
    """
    每次循环选择最小值，然后和前面的数进行交换，这种方式会保留原数组
    """
    for i in range(len(arr)):
        smallest = findSmallest(arr[i:]) + i
        temp = arr[i]
        arr[i] = arr[smallest]
        arr[smallest] = temp


arr = [5, 3, 6, 2, 10]
selectionSort2(arr)
print(arr)
# print(selectionSort(arr))
