//[C_AR05-易] 最少派車數
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1708
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int a[1000];
int N,n,m;

int main(){
    
    scanf("%d",&N);
    int max=0;
    while(N--){
        
        scanf("%d%d",&n,&m);
        
        for(int i=n;i<m;i++){
            a[i]++;
        }
        if(m>max)max=m;

    }
    int x=0;
    for(int i=0;i<max;i++){
        if(x<a[i])x=a[i];
    }
    printf("%d\n",x);
}