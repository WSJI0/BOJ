'''
1436번
영화감독 숌
'''

n=int(input())

movie=[]
for i in range(1,2666800):
    if '666' in str(i):
        movie.append(i)

print(movie[n-1])