#include <stdio.h>
#include <omp>

int fiboP(int n){
    if (n<2){


        return 1;

    }
    else{

    }
}

int main(){
    int n = 20
 
    # pragma omp parallel{
 
        #pragma omp single
        fiboP(n);
    }
}