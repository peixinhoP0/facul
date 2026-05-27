/*para executar use os seguintes comandos.

1:gcc -fopenmp fiboPar.c -o fibo
2: ./fibo
*/

#include <stdio.h>
#include <omp.h>

long long fiboP(int n){
    int x,y;
    if (n<2){
        return 1;    
    }
    else{
        #pragma omp task shared(x)
        x= fiboP(n-1);

        #pragma omp task shared(y)
        y= fiboP(n-2);

        #pragma omp taskwait
        return x+y;
    }
}

int main(){
    int n = 10;
 
    long long r;
    # pragma omp parallel
    {
 
        #pragma omp single
        {
        r= fiboP(n);
    }
}
    printf("o resultado é: %lld", r);

    return 0;
}