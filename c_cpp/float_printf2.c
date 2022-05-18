#include <stdio.h>

int main(int argc, char **argv) {
   float num = 329.14256;
   float num1 = num;
   char flt_num[30];
   int i = 0;
   
   if (num < 0.0) {
       flt_num[i++] = '-';
       num *= -1;
   }
   
   int whole = num;     // Gets us the whole number part
   num -= whole;        // Gets us the decimal part
   
   // Print the whole number part
   if (whole == 0) {
       flt_num[i++] = '0';
   } else {
       // Count the number of digits
       int digits = 0;
       int whole2 = whole;
       while (whole2 != 0) {
           whole2 /= 10;
           ++digits;
       }
       
       char buf[digits];
       int j = 0;
       while (whole != 0) {
           int digit = whole % 10;
           whole /= 10;
           buf[j++] = digit + '0';
       }
       
       for (int ii = digits - 1; ii>=0; ii--) flt_num[i++] = buf[ii];
   }
   
   flt_num[i++] = '.';
   
   // Print the decimal part
   for (int j = 0; j<8; j++) {
       num *= 10.0;
       int digit = num;
       flt_num[i++] = digit + '0';
       num -= digit;
   }
   
   flt_num[i++] = '\0';
   
   printf("Original: %f\n", num1);
   printf("String V: %s\n", flt_num);
   return 0;   
}
