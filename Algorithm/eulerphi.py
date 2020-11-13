'''
오일러피(오일러 토션트 함수)
n이하의 n과 서로소인 자연수의 갯수
'''

def phi(n):
    res=n
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            while n%i==0:
                n//=i
            res-=res//i
    if n>1:
        res-=res//n
    return res