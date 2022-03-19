#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 255
char* int2bin(int num, char string[MAXLEN]){
    char test[MAXLEN];
    itoa((num %2), string, 10);
    num /= 2;
    while(num > 0){
        itoa((num % 2), test, 10);
        strcat(string, test);
        num /= 2;
    }   
    while(strlen(string) < 8){
        strcat(string, "0");
    }
    return strrev(string);
}
char* andop(char x[8], char y[8], char result[8]){
    int i;
    if((x[0] == y[0]) && (x[i] == '1')){
        strcpy(result, "1");
    } else {
        strcpy(result, "0");
    }
    for(i = 1; i < 8; i++){
        if((x[i] == y[i]) && (x[i] == '1')){
            strcat(result, "1");
        } else {
            strcat(result, "0");
        }     
    }
    return result;
}
char* xorop(char x[8], char y[8], char result[8]){
    int i;
    if(x[0] == y[0]){
        strcpy(result, "0");
    } else {
        strcpy(result, "1");
    }
    for(i = 1; i < 8; i++){
        if(x[i] == y[i]){
            strcat(result, "0");
        } else {
            strcat(result, "1");
        }     
    }
    return result;
}
char* bin2hexa(char bin[8], char hexa[2]){
    int x = atoi(bin);
    int temp = 0, i = 0;
    while(x > 0){
        if(x % 10 == 1){
            temp += pow(2, i);
        }
        i += 1;
        x /= 10;
    }
    itoa(temp, hexa, 16);
    return hexa;
}
char* bin2u(char bin[8], char u[3]){
    int x = atoi(bin);
    int temp = 0, i = 0;
    while(x > 0){
        if(x % 10 == 1){
            temp += pow(2, i);
        }
        i += 1;
        x /= 10;
    }
    itoa(temp, u, 10);
    return u;
}
char* bin2s2c(char bin[8], char s2c[4]){
    int x = atoi(bin);
    int temp2;
    temp2 = x;    
    int temp = 0, i = 0;
    while(temp2 > 0){
        if(temp2 % 10 == 1){
            temp += pow(2, i);
        }
        i += 1;
        temp2 /= 10;
    }
    if(x >= 10000000){
        temp -= 256;
    }
    itoa(temp, s2c, 10);
    return s2c;
}
char* sumop(char x1[8], char y1[8], char result[8]){
    int x = atoi(x1);
    int temp = 0;
    int i = 0;
    while(x > 0){
        if(x % 10 == 1){
            temp += pow(2, i);
        }
        i += 1;
        x /= 10;
    }
    int y = atoi(y1);
    i = 0;
    int temp2 = 0;
    while(y > 0){
        if(y % 10 == 1){
            temp2 += pow(2, i);
        }
        i += 1;
        y /= 10;
    }
    if(atoi(x1) > 10000000){    
        temp *= -1;
        temp += 128;
    }
    if(atoi(y1) > 10000000){
        temp2 *= -1;
        temp2 += 128;
    }
    int res = 0;
    char string[7];
    char new[7];
    char abc[8];
    res = (temp + temp2);
    if(res >= -128 || res <=127){
        if(res < 0){
            res *= -1;
            int2bin(res, string);
            strcpy(result, "1");
            strncpy(new, string+(strlen(string)-7), 7);
            strcat(result, new); 
        } else {
            int2bin(res, abc);
            strncpy(result, abc+(strlen(abc)-8), 8);
        }
    } else {
        if(res < 0){
            res *= -1;
        }
        int2bin(res, abc);
        strncpy(result, abc+(strlen(abc)-8), 8);
    }
    return result;
}
char* orop(char x[8], char y[8], char result[8]){
    int i;
    if((x[0] == '1') || (y[0] == '1')){
        strcpy(result, "1");
    } else {
        strcpy(result, "0");
    }
    for(i = 1; i < 8; i++){
        if((x[i] == '1') || (y[i] == '1')){
            strcat(result, "1");
        } else {
            strcat(result, "0");
        }     
    }
    return result;
}
char* mulop(char x1[8], char y1[8], char result[8]){
    int x = atoi(x1);
    int temp = 0;
    int i = 0;
    while(x > 0){
        if(x % 10 == 1){
            temp += pow(2, i);
        }
        i += 1;
        x /= 10;
    }
    int y = atoi(y1);
    i = 0;
    int temp2 = 0;
    while(y > 0){
        if(y % 10 == 1){
            temp2 += pow(2, i);
        }
        i += 1;
        y /= 10;
    }
    if(atoi(x1) > 10000000){
        temp *= -1;
        temp += 128;
    }
    if(atoi(y1) > 10000000){
        temp2 *= -1;
        temp2 += 128;
    }
    int res = 0;
    char abc[8];
    res = (temp * temp2);
    if(res < 0){
        res *= -1;
    }
    int2bin(res, abc);
    strncpy(result, abc+(strlen(abc)-8), 8);
    return result;
}
int main(){
    int NIM;
    printf("Program untuk menghitung operasi bitwise dengan masukan NIM (diambil digit kedua ketiga, dan 3 digit terakhir).\n");
    printf("Masukkan NIM anda : ");
    scanf("%d", &NIM);
    int NIMs[8];
    int temp = NIM;
    int i = 7;
    while(temp > 0){
        NIMs[i] = temp % 10;
        i -= 1;
        temp /= 10;
    }
    int A = NIMs[1] * pow(10,4) + NIMs[2] * pow(10,3) + NIMs[5] * pow(10,2) + NIMs[6] * pow(10,1) + NIMs[7] * pow(10,0);
    char nimb[MAXLEN];
    int2bin(A, nimb);
    char Ab[8];
    strncpy(Ab, nimb + (strlen(nimb) - 8), 8);
    printf("NIM anda dalam bentuk binary (%d) : %s\n", A, nimb);
    printf("A dalam binary (least significant byte) : %s\n", Ab);
    printf("--------------------------------------------\n");
    printf("x = 10100101 dan y = 11101111\n");
    printf("Soal pertama : (A & y) ^ x\n");
    char x[8] = "10100101";
    char y[8] = "11101111";
    char resultA[8], resultA2[8];
    andop(Ab, y, resultA);
    xorop(resultA, x, resultA2);
    printf("Binary : %s\n", resultA2);
    char hexa1[2], u1[3], s2c1[4];
    bin2hexa(resultA2, hexa1);
    bin2u(resultA2, u1);
    bin2s2c(resultA2, s2c1);
    printf("Hexa : %s\n", hexa1);
    printf("Unsigned : %s\n", u1);
    printf("Signed 2C : %s\n", s2c1);
    printf("--------------------------------------------\n");
    printf("x = 11011011 dan y = 11110011\n");
    printf("Soal Kedua : (~(y >> 4) & x) + A\n");
    char x2[8] = "11011011";
    char y2[8] = "11110000"; //sudah dishift dan dinegasikan
    char resultB[8], resultB2[8];
    andop(y2, x2, resultB);
    sumop(resultB, Ab, resultB2);
    printf("Binary : %s\n", resultB2);
    char hexa2[2], u2[3], s2c2[4];
    bin2hexa(resultB2, hexa2);
    bin2u(resultB2, u2);
    bin2s2c(resultB2, s2c2);
    printf("Hexa : %s\n", hexa2);
    printf("Unsigned : %s\n", u2);
    printf("Signed 2C : %s\n", s2c2);
    printf("--------------------------------------------\n");
    printf("x = 00101111 dan y = 10100101\n");
    printf("Soal Kedua : ((x >> 2) | y) * A\n");
    char x3[8] = "00001011"; // sudah dishift 2 kanan
    char y3[8] = "10100101"; 
    char resultC[8], resultC2[8];
    orop(x3, y3, resultC);
    mulop(resultC, Ab, resultC2);
    printf("Binary : %s\n", resultC2);
    char hexa3[2], u3[3], s2c3[4];
    bin2hexa(resultC2, hexa3);
    bin2u(resultC2, u3);
    bin2s2c(resultC2, s2c3);
    printf("Hexa : %s\n", hexa3);
    printf("Unsigned : %s\n", u3);
    printf("Signed 2C : %s\n", s2c3);
    printf("--------------------------------------------\n");
}