//[C_AR13-易] 平面魔方
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1945
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int N,len;
    char str[100];
    int matrix[100][100];
    scanf("%d",&N);
    while(N--){
        scanf("%d%s",&len,str);
        int count=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                matrix[i][j]=count++;
            }
        }
        for(int ptr=0;ptr<strlen(str);ptr++){
            if(str[ptr]=='L'){
                int x=0;
                int temp[10000];
                for(int i=0;i<len;i++){
                    for(int j=0;j<len;j++){
                        temp[x++]=matrix[i][j];
                    }
                }
                for(int j=len-1;j>=0;j--){
                    for(int i=0;i<len;i++){
                        matrix[i][j]=temp[--x];
                    }
                }
            }
            if(str[ptr]=='R'){
                int x=0;
                int temp[10000];
                for(int i=0;i<len;i++){
                    for(int j=0;j<len;j++){
                        temp[x++]=matrix[i][j];
                    }
                }
                for(int j=0;j<len;j++){
                    for(int i=len-1;i>=0;i--){
                        matrix[i][j]=temp[--x];
                    }
                }
            }
            if(str[ptr]=='N'){
                int x=0;
                int temp[10000];
                for(int i=0;i<len;i++){
                    for(int j=0;j<len;j++){
                        temp[x++]=matrix[i][j];
                    }
                }
                for(int i=0;i<len;i++){
                    for(int j=len-1;j>=0;j--){
                        matrix[i][j]=temp[--x];
                    }
                }
            }
        }
        //print
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                printf("%5d",matrix[i][j]);
            }
            puts("");
        }
        if(N)puts("");
    }

}