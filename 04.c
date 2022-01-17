//[C_AR04-易] 邊緣偵測
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1703
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int a[1000][1000];// map
int N,n,m;

void print(){// 2的點輸出為0 其他為底線
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==2)printf("0 ");
            else printf("_ ");

        }puts("");
    }
}
int main(){
    
    scanf("%d",&N);
    int h=0;
    while(N--){
        if(h)puts("");
        h++;
        scanf("%d%d",&n,&m);
        
        // 讀入地圖
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        // 若看到的點自己是1並且附近有人也是0，則設定為邊緣=2
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1){
                    if(a[i-1][j]==0&&i!=1)a[i][j]=2;
                    if(a[i+1][j]==0&&i!=n)a[i][j]=2;
                    if(a[i][j-1]==0&&j!=1)a[i][j]=2;
                    if(a[i][j+1]==0&&j!=m)a[i][j]=2;
                }
            }
        }
        
        print();
        
    }
}
/*
2
5 7
0 0 0 0 0 0 0
0 0 1 1 1 0 0
0 1 1 1 1 1 0
0 0 1 1 1 0 0
0 0 0 0 0 0 0
8 11
0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 1 1 0 0
0 1 1 1 1 0 1 1 1 1 0
0 0 1 1 1 1 1 1 1 0 0
0 0 0 1 1 1 1 1 0 0 0
0 0 0 0 1 1 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
*/