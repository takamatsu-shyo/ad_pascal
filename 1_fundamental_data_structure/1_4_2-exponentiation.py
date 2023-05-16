import math
import time
import random

def my_exp(x, n):
    y = 1
    i = n

    while i > 0:
        if i % 2 == 1:
            return y * x
        x = x *x
        i = i / 2
    return y


base = 2 
exponent = 2 

def compare_pow(base, exponent):
    start = time.time()
    for x in range(1000):
        _base = base * random.randrange(9)
        pow(_base, exponent)
    end = time.time()
    py_math_time = end - start

    start = time.time()
    for x in range(1000):
        _base = base * random.randrange(9)
        my_exp(_base, exponent)
    end = time.time()
    my_exp_time = end - start

    print("py math is faster: %6d %5.2f " %(exponent, 100 - ( py_math_time /  my_exp_time * 100)))



for x in range(14):
    compare_pow(base, exponent)
    base *= 2
    exponent *= 2
