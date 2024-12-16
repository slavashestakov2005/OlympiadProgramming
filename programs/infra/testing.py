import os
import sys


def read_file(filename):
    with open(filename, 'r') as f:
        data = f.readlines()
    return data


iters = 100
call_gen = 'python gen.py > test.txt'
call_slow = 'slow < test.txt > out_slow.txt'
call_fast = 'fast < test.txt > out_fast.txt'

for i in range(1, iters + 1):
    print('Test', i)
    os.system(call_gen)
    os.system(call_slow)
    os.system(call_fast)
    slow_out = read_file('out_slow.txt')
    fast_out = read_file('out_fast.txt')
    if slow_out != fast_out:
        print("FAIL!\nInput:")
        print(read_file('test.txt'))
        print("Correct output:")
        print(*slow_out)
        print("Wrong output:")
        print(*fast_out)
        sys.exit()
print("All tests passed.")
from random import choice, randint


STR = 'qwertyuiopasdfghjklzxcvbnm_$'


def rnd_str(n: int) -> str:
    return ''.join(choice(STR) for i in range(n))


def rnd():
    n = randint(5, 10)
    ln = randint(15, 20)
    s = rnd_str(ln)
    print(n)
    print(ln, s, sep=' ')
    for i in range(n):
        ai = 10 ** 9
        print(randint(-ai, ai), end=' ')
    print()


rnd()
