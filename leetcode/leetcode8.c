int myAtoi(char* s) {
    long long nbr = 0;
    int sign = 1;
    int i = 0;
    while(s[i] == ' ' || (s[i] >= 1 && s[i]<= 31)){
        i++;
    }    
    if(s[i] == '-' || s[i] == '+'){
        if(s[i] == '-'){
            sign = -1;
        }
        i++;
    }
    if(!(s[i]>='0' && s[i]<='9')){
        return 0;
    }
    while(s[i]>='0' && s[i]<='9'){
        nbr *= 10;
        nbr += s[i] - 48;
        if(nbr > 2147483648 && sign == -1){
            return -2147483648;
        }
        if(nbr >= 2147483648 && sign == 1){
            return 2147483647;
        }
        i++;
    }
    nbr *= sign;
    return (int)nbr;
}

#include <stdio.h>
int main(){
    printf("%d\n", myAtoi("20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
    printf("%d\n", myAtoi("-87420423847204920"));
    printf("%d\n", myAtoi("       6318h392"));
    printf("%d\n", myAtoi("   -d234"));
    printf("%d\n", myAtoi(" hello"));
    printf("%d\n", myAtoi("  +173"));
    printf("%d\n", myAtoi("+911"));
}