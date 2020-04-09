'''
이분탐색 알고리즘

biSearch(e, target)
biSearch(찾을 요소, 검색 대상)

만약 e가 target에 있을 경우 1, 없으면 0을 return 함.

검색대상은 실수로 이루어진 정렬된 리스트형태여야 함.
'''

def biSearch(e, target):
    left=0
    right=len(target)-1
    while left<=right:
        mid=(left+right)//2
        if target[mid]>e:
            right=mid-1
        elif target[mid]<e:
            left=mid+1
        else:
            return 1
            break
    return 0