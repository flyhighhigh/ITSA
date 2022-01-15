//[C_AR03-易] 計算陣列中所有元素的立方和
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1291
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int a;
    char str[4096],temp[12];
    while(fgets(str,4096,stdin)!=NULL){
        int idx=0,i=0,sum=0;
        while(i<(int)strlen(str)){
            if(isspace(str[i])){i++;continue;}
            sscanf(str+i,"%s",temp);
            a=atoi(temp);
            sum+=a*a*a;
            i+=strlen(temp);
        }
        printf("%d\n",sum);
    }
}