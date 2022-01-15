//[C_AR17-中] 不同基底整數轉換
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2033
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

    char cvt[]="0123456789ABCDEF";
    char x1[1000];
    int b1,b2;

    scanf("%s%d%d",x1,&b1,&b2);

    if(b1<2||b1>16||b2<2||b2>16){
        printf("Input Error\n");
        return 0;
    }
    int sum=0;
    for(int i=0;i<strlen(x1);i++){
        if(strchr(cvt,x1[i])==NULL){
            printf("Input Error\n");
            return 0;
        }
        
        int a=strchr(cvt,x1[i])-cvt;
        if(a>=b1){
            printf("Input Error\n");
            return 0;
        }
        sum=sum*b1+a;
    }
    int idx=0;
    char result[1000];
    while(sum){
        result[idx++]=cvt[sum%b2];
        sum/=b2;
    }
    result[idx]='\0';
    rev(result);
    printf("%s\n",result);
    

}