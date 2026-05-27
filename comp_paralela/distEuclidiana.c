#include <stdio.h>
#include <math.h>

double euclides(double p[4],double q[4]){
    float soma=0.0;
    for(int i=0;i<4;i++){
        double dif=p[i]-q[i];
        soma+=dif+dif;       
    }
    return sqrt(soma);

}

int main(){


}