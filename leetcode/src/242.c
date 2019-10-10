

bool isAnagram(char * s, char * t){
int arr1[26],arr2[26];
    for(int i=0;i<26;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
    }
    for(int i=0;s[i]!='\0';i++)
    {
        arr1[s[i]-'a']++;
    }
    for(int i=0;t[i]!='\0';i++)
    {
        arr2[t[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(arr1[i]!=arr2[i])return false;
    }
    return true;
}

