//[C_AR01-易] 一維陣列反轉 I
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=274  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<ctype.h>  
  
int main(){  
    int a[1000];  
    char str[4096],temp[12];  

    while(fgets(str,4096,stdin)!=NULL){// 一次讀入一行
        int idx=0,i=0;// i計現在看到幾個字

        while(i<(int)strlen(str)){// 還沒到結尾的時候
            if(isspace(str[i])){i++;continue;}  

            sscanf(str+i,"%s",temp);  
            a[idx++]=atoi(temp);  
            i+=strlen(temp);  
        }  
        for(int j=idx-1;j>=0;j--){// 輸出
            printf("%d",a[j]);  
            if(j)printf(" ");  
            else printf("\n");  
        }  
    }  
}  