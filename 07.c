//[C_AR07-中] 有違反數獨的規則嗎？
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1763
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int a[100][100];
int N,n,m;

int row_correct(int x){
    int check[10]={0};
    for(int i=1;i<=9;i++){
        if(a[x][i])check[a[x][i]]++;
        if(check[a[x][i]]>1){
            printf("row%d #%d\n",x,a[x][i]);
            return 0;
        }
    }
    return 1;
}
int col_correct(int x){
    int check[10]={0};
    for(int i=1;i<=9;i++){
        if(a[i][x])check[a[i][x]]++;
        if(check[a[i][x]]>1){
            printf("column%d #%d\n",x,a[i][x]);
            return 0;
        }
    }
    return 1;
}
int block_correct(int x,int y){
    int x1=x*3+1;
    int x2=x*3+3;
    int y1=y*3+1;
    int y2=y*3+3;
    int check[10]={0};
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(a[i][j])check[a[i][j]]++;
            if(check[a[i][j]]>1){
                printf("block%d #%d\n",x*3+y+1,a[i][j]);
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int flag=1;
    char c[20];
    for(int i=1;i<=9;i++){
        scanf("%s",c);
        for(int j=1;j<=9;j++){
            a[i][j]=c[j-1]-'0';
        }
    }
    for(int i=1;i<=9;i++){
        if(!row_correct(i))flag=0;
    }
    for(int i=1;i<=9;i++){
        if(!col_correct(i))flag=0;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!block_correct(i,j))flag=0;
        }
    }
    if(flag)printf("true\n");
}
/*
988459289
956789523
659723456
231564807
504897231
897231564
302605978
605978412
908312605
*/