'''
4673번
셀프 넘버
'''

no=[]
for i in range(9969):
    if i<10:
        no.append(i*2)
    if i>=10 and i<100:
        no.append(int(str(i)[0])+int(str(i)[1])+i)
    if i>=100 and i<1000:
        no.append(int(str(i)[0])+int(str(i)[1])+int(str(i)[2])+i)
    if i>=1000 and i<10000:
        no.append(int(str(i)[0])+int(str(i)[1])+int(str(i)[2])+int(str(i)[3])+i)
no=sorted(no)

for i2 in range(9994):
    if no.count(i2)==0:
        print(i2)
        
