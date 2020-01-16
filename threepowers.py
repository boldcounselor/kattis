from sys import stdin, stdout
from math import log2
exp3=[1]

def lsb(a):
    return (-a & a)

def pow3(lsb):
    lsbi=int(log2(lsb))
    for i in range(len(exp3)-1,lsbi):
        exp3.append(exp3[-1]*3)
    return exp3[lsbi]

def main():
    for line in stdin:
        if(int(line)!=0):
            line=line.rstrip()
            n = int(line) - 1
            if(n!=1):
                stdout.write("{ ")
                while(n!=0):   
                    lsbn = lsb(n)
                    stdout.write(str(pow3(lsbn)))
                    n = n - lsbn
                    if n != 0:
                        stdout.write(", ")
                stdout.write(" }\n")
            else:
                stdout.write("{  }\n")

if __name__ == '__main__':
    main()