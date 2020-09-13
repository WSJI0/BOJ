out=open("output.txt","a")
out.write("100")
import random
for i in range(1, 101):
    out.write(str(i)+" "+str(i)+"\n")