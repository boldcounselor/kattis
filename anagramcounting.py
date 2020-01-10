from sys import stdin, stdout
from math import factorial
def main():
    factorials = {0: 1}
    for i in range(1, 101):
        factorials[i] = i * factorials[i - 1]

    for line in stdin:
        line=line.rstrip()
        perms = factorials[len(line)]
        #print(type(perms))
        chars = dict()
        for char in line:
            if char not in chars:
                chars[char] = 1
            else:
                chars[char] += 1
        for char, no in chars.items():
            #print(type(no))
            perms //= factorials[no]
        print(perms)

if __name__ == '__main__':
    main()