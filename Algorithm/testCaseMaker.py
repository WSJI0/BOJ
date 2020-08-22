out=open("output.txt","a")
out.write("1000000 100000")
import random
for _ in range(100000):
    out.write(str(random.randrange(0, 2))+" "+str(random.randrange(0, 1000001))+" "+str(random.randrange(0, 1000001))+"\n")