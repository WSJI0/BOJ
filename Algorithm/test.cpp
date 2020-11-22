#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dice_toss();// 함수 원형 선언 

int main()
{
   int toss=0, one=0, two=0, three=0, four=0, five=0, six=0, d;
   srand((unsigned)time(NULL));
   
   for(toss = 0; toss < 100; toss++)
   {
       d=dice_toss();
      if(d==1) one++;
      else if(d==2) two++;
      else if(d==3) three++;
      else if(d==4) four++;
      else if(d==5) five++;
      else if(d==6) six++;
   }
   
   printf("숫자1이 나온 횟수:%d\n", one);
   printf("숫자2이 나온 횟수:%d\n", two);
   printf("숫자3이 나온 횟수:%d\n", three);
   printf("숫자4이 나온 횟수:%d\n", four);
   printf("숫자5이 나온 횟수:%d\n", five);
   printf("숫자6이 나온 횟수:%d\n", six);
   
   return 0;
   
 }
 
 
int dice_toss()
{
   int i;
   i =rand()%6+1;
   return i;
   
}