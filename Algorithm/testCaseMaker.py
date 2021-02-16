out=open("output3.txt","a")

import sys
input=sys.stdin.readline

out.write("3000")

for i in range(1000000, 996999, -1):
    out.write(str(i+1)+"\n")

out.close()