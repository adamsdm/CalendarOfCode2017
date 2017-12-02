#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int calcChecksum(char *line);

#define INFINITY    1.0 / 0.0;

int main(void){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    // Read file input
    fp = fopen("input.txt", "r");
    if (fp == NULL)
        return -1;

    int totChecksum = 0;
    while ((read = getline(&line, &len, fp)) != -1){
        totChecksum += calcChecksum(line);
    }

    printf("Checksum: %d", totChecksum);    

    fclose(fp);
    if (line)
        free(line);
    return 1;
}

int calcChecksum(char *line){

    int min =   99999;
    int max = -99999;

    // Split line by empty spaces, what are we living for?
    char *splitted = strtok(line, " \t");
    while (splitted != NULL)
    {
        int n = atoi(splitted);
        if(n > max) max = n;
        if(n < min) min = n;
        splitted = strtok(NULL, " \t");
    }

    return max - min;
}