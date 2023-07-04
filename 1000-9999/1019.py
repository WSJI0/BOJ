s=input()
cnt=[0 for _ in range(10)]

if int(s)<10:
    for i in range(1, int(s)+1):
        cnt[i]+=1
    print(*cnt)
elif int(s)==10:
    print("1 2 1 1 1 1 1 1 1 1")
else:
    for i in range(len(s)):
        for j in range(10):
            if i==0 and j==0: continue
            if int(s[i])!=j:
                if i==0: 
                    if int(s[i])>j:
                        cnt[j]+=pow(10, len(s)-1)
                else:
                    tmp=""
                    for k in range(i): tmp+=s[k]
                    if int(s[i])>j and j!=0:
                        tmp=int(tmp)+1
                    tmp=int(tmp)
                    for k in range(len(s)-i-1): tmp*=10
                    cnt[j]+=tmp
            elif int(s[i])==j:
                if int(s[i])==0:
                    tmp=""
                    for k in range(len(s)):
                        if k==i: 
                            tmp=str(int(tmp)-1)
                            continue
                        tmp+=s[k]
                    cnt[0]+=int(tmp)+1
                else:
                    tmp=""
                    for k in range(len(s)):
                        if k==i: continue
                        tmp+=s[k]
                    tmp=int(tmp)
                    if j!=0: tmp+=1
                    cnt[j]+=tmp

    print(*cnt)
