from random import randrange
f = open("input.txt", "a")
n = randrange(30,50)
list = [randrange(-100,100) for _ in range(n)]
f.write(f"{str(n)}\n")
for i in list:
    f.write(f"{str(i)} ")
f.close()