import time
startTime=time.time()

def GCD(A, B):
    return B if A%B==0 else GCD(B, A%B)

print(GCD(36,20))

print("Time:", time.time()-startTime)