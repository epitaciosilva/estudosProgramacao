from sys import argv
from contextlib import redirect_stdout
from math import factorial

def bin_off(n, k):
    res = 1
    if k > n:
        k = n
    for i in range(k+1):
        res = factorial(n) // (factorial(n-i) * factorial(i))
        print(res, end=" ")
    print()

if __name__ == "__main__":
    n = int(argv[1])
    k = int(argv[2])
    with open("triangle.out", "w", encoding="utf-8") as out:
        with redirect_stdout(out):
            for i in range(n+1):
                limit = i+1 if i != n else k+1
                bin_off(i, limit)
