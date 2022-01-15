//[C_AR06-易] 字串在哪裡?
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1760
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char a[1000];
char table2[30][30];
int N,n,m;

int main(){
    
    scanf("%s",a);
    if(strlen(a)>10){
        printf("Target Overflow\n");
        return 0;
    }

    char str[4096];
    char *all[30];
    
    int idx=0;

    while(scanf("%s",str)!=EOF){  
        if(strlen(str)>20){
            printf("Array Overflow\n");
            return 0;
        }
        all[idx++]=strdup(str);
    }
    if(idx>20){
        printf("Array Overflow\n");
        return 0;
    }
    int m=strlen(all[0]);
    for(int i=0;i<idx;i++){
        for(int j=0;j<m;j++){
            //all[i][j]
            //左
            //printf("%d %d\n",i,j);
            for(int x=0;x<=strlen(a)&&j-x>=-1;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i, j - (strlen(a) - 1));
                    break;
                }
                if (j - x == -1) break;
                if(all[i][j-x]!=a[x])break;
            }
            //左上
            for(int x=0;x<=strlen(a)&&j-x>=-1&&i-x>=-1;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i - (strlen(a) - 1), j - (strlen(a) - 1));
                    break;
                }
                if (j - x == -1 || i - x == -1) break;
                if(all[i-x][j-x]!=a[x])break;
            }
            //上
            for(int x=0;x<=strlen(a)&&i-x>=-1;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i - (strlen(a) - 1), j);
                    break;
                }
                if (i - x == -1) break;
                if(all[i-x][j]!=a[x])break;
            }
            //右上
            for(int x=0;x<=strlen(a)&&i-x>=-1&&j+x<=m;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i - (strlen(a) - 1), j + (strlen(a) - 1));
                    break;
                }
                if (i - x == -1 || j + x == m) break;
                if(all[i-x][j+x]!=a[x])break;
            }
            //向右
            for(int x=0;x<=strlen(a)&&j+x<=m;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i, j + strlen(a) - 1);
                    break;
                }
                if (j + x == m) break;
                if(all[i][j+x]!=a[x])break;
            }
            //右下
            for(int x=0;x<=strlen(a)&&j+x<=m&&i+x<=idx;x++){
                if (x == strlen(a)) {
                    printf("%d, %d To %d, %d\n", i, j, i + strlen(a) - 1, j + strlen(a) - 1);
                    break;
                }
                if(j+x==m||i+x==idx)break;
                if(all[i+x][j+x]!=a[x])break;
            }
            //下
            for(int x=0;x<=strlen(a)&&i+x<=idx;x++){
                if(x==strlen(a)){
                    printf("%d, %d To %d, %d\n",i,j,i+strlen(a)-1,j);
                    break;
                }
                if(i+x==idx)break;
                if(all[i+x][j]!=a[x])break;
            }
            //左下
            for(int x=0;x<=strlen(a)&&i+x<=idx&&j-x>=-1;x++){
                if(x==strlen(a)){
                    printf("%d, %d To %d, %d\n",i,j,i+(strlen(a)-1),j-(strlen(a)-1));
                    break;
                }
                if(i+x==idx||j-x==-1)break;
                if(all[i+x][j-x]!=a[x])break;
            }
            
        }
    }
    /*
    for(int i=0;i<idx;i++){
        printf("%s\n",table2[i]);
    }
    */

}
/*
AQUR
AQDCDDS
QEAQUAF
UAQURQL
RRAAQUR
GDAQURE
FGEAUUR
WCQEERV
*/