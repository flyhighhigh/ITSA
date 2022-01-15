//[C_AR11-易] 最大權重和
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1930
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int N,m,n,k;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d",&m,&n,&k);
        int a[m][n];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int max=-0xfffffff;

        for(int i=0;i+k-1<m;i++){
            for (int j=0;j+k-1<n;j++){
                //從a[i][j]開始取矩陣
                int sum=0;
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++)//從i,j移動x,y
                        sum+=a[i+x][j+y];
                }
                if(sum>max)max=sum;
            }
        }
        printf("%d\n",max);
    }

}