def max_subarray_sum(arr):
    if len(arr) == 1:
        return arr[0]
    else:
        mid = len(arr) // 2
        left_sum = max_subarray_sum(arr[:mid])
        right_sum = max_subarray_sum(arr[mid:])
        cross_sum = max_crossing_sum(arr, mid)
        return max(left_sum, right_sum, cross_sum)

def max_crossing_sum(arr, mid):
    left_sum = float('-inf')
    right_sum = float('-inf')
    curr_sum = 0
    for i in range(mid-1, -1, -1):
        curr_sum += arr[i]
        if curr_sum > left_sum:
            left_sum = curr_sum
    curr_sum = 0
    for i in range(mid, len(arr)):
        curr_sum += arr[i]
        if curr_sum > right_sum:
            right_sum = curr_sum
    return left_sum + right_sum

arr=[-3,1,-8,12,0,-3,5,-9,4]
print(max_subarray_sum(arr))