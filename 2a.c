#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define C 2.9979
#define E 1.602
#define m0 9.109
#define MAXLEN 255
int main(){
    char namafile[MAXLEN];
    printf("Masukkan nama file berisi Tegangan: ");
    scanf("%s", &namafile);
    FILE* vfile = fopen(namafile, "r");
    char line[MAXLEN];
    float Tegangan[MAXLEN];
    int count = 0;
    while(fgets(line, MAXLEN, vfile)){
        Tegangan[count] = atof(line);
        count+=1;
    }    
    int i;
    float m[count], mpow[count], v[count], vpow[count];
    for(i = 0; i < count; i++){
        m[i] = (Tegangan[i]*E*pow(10,-4)/(C*C)) + m0;
        mpow[i] = -31;
        while(m[i] >= 10){
            mpow[i] += 1;
            m[i] /= 10;
        }
        v[i] = C * pow((1-pow((m0*pow(10,-31-mpow[i])/m[i]),2)), 0.5);
        vpow[i] = 8;
        while(v[i] <= 1){
            vpow[i] -= 1;
            v[i] *= 10;
        }
        printf("Untuk tegangan %.0f, didapatkan m = %.3f x 10^(%.0f) dan v = %.3f x 10^(%.0f)\n", Tegangan[i], m[i], mpow[i], v[i], vpow[i]);
    }
}