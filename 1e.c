#include <stdio.h>

int main(){
    signed int a,b,c;
    a = -37;
    b = -111;
    c = 51;
    printf("%d", ((c & b) ^ a));
}