//[C_AR09-易] 兩數差值
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1906
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void rev(unsigned char *str) {
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen((const char *)str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

int main(){
    int flag=1;
    char str[10];
    char min[10];
    char* max;
    int count[12]={0};
    int num;

    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        if(!isdigit(str[i]))continue;
        count[str[i]-'0']++;
    }
    int idx=0;
    for(int i=0;i<=9;i++){
        if(count[i]==0)continue;
        for(int j=0;j<count[i];j++){
            min[idx++]=i+'0';
        }
    }
    min[idx]='\0';
    max=strdup(min);
    rev(max);
    
    printf("%d\n",atoi(max)-atoi(min));
}