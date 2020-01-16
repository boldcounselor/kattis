import os, sys, string, random
from math import gcd
def phi(n):
    amount = 0        
    for k in range(1, n + 1):
        if gcd(n, k) == 1:
            amount += 1
    return amount

def main():
    sys.stdout = open('farey.txt','wt')
    n = 10000
    output = [0, 1]
    for i in range(2,n+1):
        output.append(phi(i))
    print(output)

if __name__ == '__main__':
    main()