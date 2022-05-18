#include <stdio.h>

int precision = 6;

void printDouble(double num)
{
   char flt_num[64];
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
   for (int j = 0; j<precision; j++) {
       num *= 10.0;
       int digit = num;
       flt_num[i++] = digit + '0';
       num -= digit;
   }
   
   flt_num[i++] = '\0';
   
   // TODO: Replace with proper system call or println
   puts(flt_num);
}

void printFloat(float num)
{
    printDouble(num);
}

void setPrecision(int p)
{
    precision = p;
}

int main(int argc, char **argv) {
   float num = 329.14256;
   
   printf("Original: %f\n", num);
   printf("String V: ");
   printDouble(num);
   
   setPrecision(2);
   printf("Precision 2: ");
   printDouble(num);
   return 0;   
}

