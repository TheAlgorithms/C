char * defangIPaddr(char * address){
    int i = 0;
    char *ans, *temp;
    
    for (; address[i] != '\0'; i++); // Get address size
    if(!(ans = (char *)malloc(i + 7))) {    // Allocate mem
        printf("Failed Malloc\n");
        exit(0);
    }   
    
    temp = ans;
    while(*address) {
        if(*address == '.') {
            *ans++ = '[';
            *ans++ = *address++;
            *ans++ = ']'; 
        } else {
            *ans++ = *address++;
        }
    }
    *ans = '\0';
    return temp;
}
