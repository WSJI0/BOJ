out=open("output2.txt","a")

import sys
input=sys.stdin.readline

out.write("10000")

for i in range(10000):
    out.write(str(i+1)+"\n")

out.close()