#include<stdio.h>

int main(){
    unsigned long int T;
    int str1[256], str2[256];
    char temp;
    unsigned int i;
    unsigned int count = 0;
    for(i=0; i < 256; i++){
        str1[i] = 0;
        str2[i] = 0;
    }
    scanf("%lu",&T);
    getchar();
    while(T>0){
        temp = getchar();
        while(temp!='\n'){
            str1[temp]++;
            temp = getchar();
        }
        temp = getchar();
        while(temp!='\n' && temp!=EOF){
            str2[temp]++;
            temp = getchar();
        }
        
        for(i=0; i < 256; i++){
            if(str1[i] > str2[i]) count += (str1[i] - str2[i]);
            else if(str2[i] > str1[i]) count += (str2[i] - str1[i]);
            str1[i] = 0;
            str2[i] = 0;
        }
        printf("%u\n", count);
        T--;
        count = 0;
    }
    return 0;
}