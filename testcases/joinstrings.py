import os,sys,string,random

def id_generator(size=10, chars=string.ascii_lowercase):
    return ''.join(random.choice(chars) for _ in range(size))

def main():
    sys.stdout = open('joinstrings.txt','wt')
    n = int(input())
    output = []
    print(n)
    for i in range(1,n+1):
        gen_string = id_generator()
        print(gen_string)
        output.append(gen_string)
    for i in range(1,n):
        print("{} {}".format(1,i+1))
    print(''.join(output))

if __name__ == '__main__':
    main()