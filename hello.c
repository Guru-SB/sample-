// // Online C compiler to run C program online
// #include <stdio.h>

// int main() {
//     // Write C code here
  
//     int d=0b10001;
//     d^=0b11111;
//     printf("%d",d);
//     return 0;
// }

#include <stdio.h>
#include <stdio.h>

int main() {

    int x = 0b1011;

    x = ~x;
    int n=0b1011;
    n ^= 0b1111;

    printf("%d\n", x);
    printf("%d \n", n);

    return 0;
}