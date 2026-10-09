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
