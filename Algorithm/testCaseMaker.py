out=open("output3.txt","a")

import sys
input=sys.stdin.readline

out.write("1024 1\n")

for i in range(1024):
    for j in range(1024):
        out.write(str(1000)+" ")
    out.write("\n")

out.write("1 1 1 1024 1024")


out.close()