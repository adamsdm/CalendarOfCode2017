#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    

    if(argc!=2){
        printf("Usage: captcha <NUMBER>.\n");
        return -1;
    }

    char *input;
    input = argv[1];
    
    size_t i;
    size_t length = strlen(input);
    int sum = 0;
    for (i = 0; i < length; i++){

        // Special case for last char
        char currChar = input[i];
        char nextChar = ((i != length-1) ? (input[i+1]) : (input[0]));

        if(currChar == nextChar){
            sum += currChar - '0';
        }
            
    }
    
    printf("The sum is %d\n", sum);
    return 1;
}