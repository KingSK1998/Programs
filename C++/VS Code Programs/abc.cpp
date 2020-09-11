//#include <iostream>
#include <stdio.h>
int main(){
    char c[] = "2019ABCD";
    char *p = c;
    printf("p+p[3]-p[1]: %s\n", p+p[3]-p[1]);
}
//