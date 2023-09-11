#include <iostream>

using namespace std;

unsigned long int cont_op = 0; // global
unsigned long int f( int n ) {
cont_op++;
if(n <= 1) return 1;
if ((n % 2) == 0)
return f(n-1) + f(n-2);
else
return ((f(n-3) + f(n-1) * f(n-2)) >> 2) + 1;
}

int main (){
int n=0;
for (int i = 1; i <= 39; i++){
	n = f (i);
	cout<<i<<";"<<cont_op<<endl;
	cont_op = 0;
}
}