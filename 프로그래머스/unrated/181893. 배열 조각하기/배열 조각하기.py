def solution(arr, query):
    for index in range(0, len(query)):
        if index % 2 == 0:
            arr = arr[:query[index] + 1]
        else:
            arr = arr[query[index]:]
    return arr