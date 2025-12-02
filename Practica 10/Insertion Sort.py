def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    return arr


if __name__ == "__main__":
    lista = [12, 5, 3, 7, 2]
    print("Lista original:", lista)
    print("Lista ordenada:", insertion_sort(lista))
