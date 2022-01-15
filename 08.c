//[C_AR08-易] 找出數字字串中的最大質數  
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1769  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<ctype.h>  
  
int N,n,m;  
int isprime(int num){  
    if(num==1)return 0;  
    else{  
        for(long long i=2;i*i<=num;i++){  
            if((num%i)==0)return 0;  
        }  
        return 1;  
    }  
}  
  
int main(){  
    int flag=1,max=1;  
    char str[20];  
    char temp[20];  
    int num;  
  
    scanf("%s",str);  
    for(int i=1;i<=strlen(str);i++){//擷取幾個字  
        for(int j=0;j+i-1<strlen(str);j++){//從哪裡開始截  
            for(int x=0;x<i;x++){//已經結了幾個  
                temp[x]=str[x+j];  
            }  
            temp[i]='\0';  
            num=atoi(temp);  
            if(isprime(num) && num>max)max=num;  
        }  
    }  
    if(max==1)printf("No prime found\n");  
    else printf("%d\n",max);  
}  
/* 
15693 
48814 
*/  