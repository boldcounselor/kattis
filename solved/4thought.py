from sys import stdin, stdout
from itertools import product
m = int(stdin.readline())
alphabets = "+-*/"
ops = [i for i in product(alphabets, repeat=3)]
possible_values = {}
for op in ops:
    eqn = f"4 {op[0]} 4 {op[1]} 4 {op[2]} 4"
    res = eval(eqn.replace("/", "//"))
    possible_values[res] = f"{eqn} = {res}"
#print(ops)
for _ in range(m):
    n = int(stdin.readline())
    if n in possible_values:
        print(possible_values[n])
    else:
        print("no solution")
