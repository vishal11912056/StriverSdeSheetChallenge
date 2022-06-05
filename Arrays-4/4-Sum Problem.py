def fourSum(arr, target):
    # O(N^3) + O(NlogN)
    arr.sort()
    n = len(arr)
    for i in range(n-3):
        for j in range(i+1, n-2):
            l, r = j+1, n-1
            while l < r:
                val = arr[l] + arr[r]
                if arr[i] + arr[j] + val == target:
                    return "Yes"
                if arr[i] + arr[j] + val < target:
                    l += 1
                else:
                    r -= 1
    return "No
