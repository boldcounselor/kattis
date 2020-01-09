import sys

def main():
    for line in sys.stdin:
        line.rstrip()
        perms = factorial(line.len())
        chars = dict()
        for char in line:
            if char in chars:
                chars[char] = 1
            else:
                chars[char] += 1
        for char, no in chars.items():
            perms /= no
    print(perms)