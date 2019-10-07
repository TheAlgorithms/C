// C program to convert an Octal number to Binary 
  
#include <stdio.h>
  
// Function to convert an Octal to Binary Number 
string OctToBin(string octnum) 
{ 
    long int i = 0; 
  
    string binary = ""; 
  
    while (octnum[i]) { 
        switch (octnum[i]) { 
        case '0': 
            binary += "000"; 
            break; 
        case '1': 
            binary += "001"; 
            break; 
        case '2': 
            binary += "010"; 
            break; 
        case '3': 
            binary += "011"; 
            break; 
        case '4': 
            binary += "100"; 
            break; 
        case '5': 
            binary += "101"; 
            break; 
        case '6': 
            binary += "110"; 
            break; 
        case '7': 
            binary += "111"; 
            break; 
        default: 
            cout << "\nInvalid Octal Digit "
                 << octnum[i]; 
            break; 
        } 
        i++; 
    } 
  
    return binary; 
} 
  
// Driver code 
int main() 
{ 
    // Get the octal number 
    string octnum = "345"; 
  
    // Convert Octal to Binary 
    cout << "Equivalent Binary Value = "
         << OctToBin(octnum); 
  
    return 0; 
} 

