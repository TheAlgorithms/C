char * defangIPaddr(char * address){
    
    int length = strlen(address), j = 0;
    char * returnIp = malloc((length + 7));
    
    for (int i = 0; i < length; i++)
    {
        if (address[i] != '.')
        {
            *(returnIp + j) = address[i];
            j++;
        }
        else
        {
            *(returnIp + j) = '[';
            *(returnIp + (j + 1)) = '.';
            *(returnIp + (j + 2)) = ']';
            j += 3;
        }
    }
    
    *(returnIp + j) = '\0';
    
    return returnIp;
}
