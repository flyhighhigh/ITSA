//[C_AR01-易] 一維陣列反轉 I
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=274  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<ctype.h>  
  
int main(){  
    int a[1000];  
    char str[4096],temp[12];  
    while(fgets(str,4096,stdin)!=NULL){  
        int idx=0,i=0;  
        while(i<(int)strlen(str)){  
            if(isspace(str[i])){i++;continue;}  
            sscanf(str+i,"%s",temp);  
            a[idx++]=atoi(temp);  
            i+=strlen(temp);  
        }  
        for(int j=idx-1;j>=0;j--){  
            printf("%d",a[j]);  
            if(j)printf(" ");  
            else printf("\n");  
        }  
    }  
}  