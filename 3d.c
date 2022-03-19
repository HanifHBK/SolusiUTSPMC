#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char NIM[8];
    printf("Program untuk menghitung nilai Vout rangkaian RC dengan spesifikasi sebagai berikut.\n");
    printf("Nilai R adalah digit keempat dan kelima NIM yang akan anda input (dalam kOhm)\n");
    printf("Nilai C adalah digit pertama, kedua, ketiga, keenam, ketujuh dan kedelapan NIM anda (dalam pF)\n");
    printf("Nilai Vin adalah tetap yaitu 5V.\n");
    printf("Masukkan NIM anda : ");
    scanf("%s", &NIM);
    char Rs[2];
    char Cs1[2];
    char Cs2[4];
    strncpy(Rs, NIM + 3, 2);
    strncpy(Cs1, NIM, 3);
    strncpy(Cs2, NIM + 5, 3);
    char Cs[6];
    strncpy(Cs, Cs1, 3);
    strcat(Cs, Cs2);
    double R, C;
    R = atof(Rs);
    C = atof(Cs);
    printf("Dari data NIM anda, maka diperoleh nilai R dan C berturut turut adalah %.0f kOhm dan %.0f pF\n", R, C);
    double time;
    printf("Masukkan nilai waktu (dalam s) yang ingin anda cari tegangan Voutnya (gunakan . sebagai pemisah desimal) : ");
    double result;
    scanf(" %lf", &time);
    double time_constant = R * C * pow(10, -9);
    result = 5 - (5 * exp(-time/time_constant));
    printf("Nilai time constant berdasarkan NIM anda : %lf\n", time_constant);
    printf("Pada saat t = %lf s nilai Tegangan Vout adalah = %lf V\n", time, result);
    double tunak = 0;
    result = 5 - (5 * exp(-tunak/time_constant));
    while(result != 5){
        tunak += 0.000001;
        result = 5 - (5 * exp(-tunak/time_constant));
    }
    printf("Rangkaian tunak pada saat t = %lf s", tunak);
}