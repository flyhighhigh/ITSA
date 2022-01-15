//[C_AR15-易] 保齡球計分
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1972
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int row,col,l;
        scanf("%d%d%d",&row,&col,&l);

        //set to 0
        int a[row+2][col+2];
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                a[i][j]=0;
            }
        }

        int x,y;
        for(int i=0;i<l;i++){
            scanf("%d%d",&x,&y);
            a[x][y]++;
            a[x-1][y]++;
            a[x+1][y]++;
            a[x][y-1]++;
            a[x][y+1]++;
        }
        int success=1;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(a[i][j]==0)success=0;
                //printf("%d ",a[i][j]);
            }
            //puts("");
        }
        printf("%c\n",success?'Y':'N');
            

        
    }

}