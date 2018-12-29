#!/usr/bin/python3
import ctypes
import sys

so = ctypes.CDLL("./libvar1.so")


## --> SQUARE_FILT <-- ##

# Извлекаю ф-ю фильтрации массива по корням из библиотеки
_square_filt = so.square_filt
# Задаю ей аргументы
_square_filt.argtypes = (ctypes.POINTER(ctypes.c_int), \
        ctypes.POINTER(ctypes.c_int))
# Задаю тип возвращаемого значения
_square_filt.restype = ctypes.POINTER(ctypes.c_int)



def square_filt(arr):
    len_ptr = ctypes.POINTER(ctypes.c_int)
    len_ptr.contents = ctypes.c_int(len(arr))

#    print('len = ', len_ptr.contents)
    arr_ptr = (ctypes.c_int * len_ptr.contents.value)(*arr)
#    for pr in arr_ptr:
#        print(pr)

    _square_filt(arr_ptr, len_ptr.contents)

#    print('\n')
#    print("len = ", len_ptr.contents)

    result = list()

    for i in range(len_ptr.contents.value):
        result.append(arr_ptr[i])

    return result


   

## --> CYCLE_SHIFT <-- ##

# Извлекаю ф-ю cycle shift
_cycle_shift = so.cycle_shift
# Указываю тип аргументов
_cycle_shift.argtypes = (ctypes.POINTER(ctypes.c_int),\
        ctypes.c_int, ctypes.c_int)
# Указываю тип возвращаемого значения
_cycle_shift.restype = ctypes.c_int



def cycle_shift(arr, k):
    length = ctypes.c_int(len(arr))
    koef = ctypes.c_int(k)

    if length.value <= 0:
        return -1

    arr_ptr = (ctypes.c_int * length.value)(*arr)

    rc = _cycle_shift(arr_ptr, length, koef)

    result = list()

    for i in range(length.value):
        result.append(arr_ptr[i])

    return rc, result


def cycle_shift_mini_testing():
    print('\n--> int_cycle_shift_mini_testing <--')
    a = [i for i in range(10)]
    print('input massive:', a)
    print(" (cycling on 3 in left)")
    rc, a = cycle_shift(a, 3)
    print('output massive:', a)
    print("rc = ", rc)

 


def square_filt_mini_testing():
    print("\n--> square filt mini testing <--")
    a = [i for i in range(10)]
    print('input massive:', a)
    a = square_filt(a)
    print('output massive:', a)
 

def main():
    square_filt_mini_testing()
    cycle_shift_mini_testing()



if __name__ == "__main__":
    main()







