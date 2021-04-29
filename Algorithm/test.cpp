
#include <bits/stdc++.h>
using namespace std;

#define MAXT 300000
#define MAXA 25

int lenA, lenT;
string A, T;

struct stack {
   int top;
   char x[MAXT+1];
   char w[MAXA];

   void init( string& A ) {
      for( int i = 0; i < lenA; ++i ) w[i] = A[lenA-1-i];
      top = 0;
   }

   int add( char c ) {
      int ret = 0;
      x[top++] = c;
      if( top >= lenA ) {
         ret = 1;
         for( int i = 0; i < lenA; ++i ) 
            if( x[top-i-1] != w[i] ) 
               ret = 0;
         if( ret ) top -= lenA;
      }
      return ret;
   }
   void print(){
	   cout<<" print : ";
	   for(int i=0; i<top; i++) cout<<x[i]<<" ";
	   cout<<"\n";
   }
} L, D;

int main( void ) {
   /*
   cin>>A; lenA = A.length();
   cin>>T; lenT = T.length();
   L.init( A );
   reverse( A.begin(), A.end() );
   D.init( A );

   int turn = 0;
   int lpos = 0, dpos = lenT-1;
   while( lpos <= dpos ) {
	   if( turn == 0 ) turn ^= L.add( T[lpos++] );
      else turn ^= D.add( T[dpos--] );
	  L.print();
	  D.print();
	  cout<<"-------------"<<"\n";
   }
      

   D.print();
   while( L.top ){
      cout<<"added : "<<L.x[L.top-1]<<"\n";
      D.add( L.x[--L.top] );
   }

   D.print();

   while( D.top ) printf( "%c", D.x[--D.top] );
   printf( "\n" );
   */
  string A="abcd";
   L.init(A);
   L.print();

   L.add('a');
   L.print();
   L.add('b');
   L.print();
   L.add('c');
   L.print();
   L.add('d');
   L.print();
   L.add('e');
   L.print();


   return 0;
}