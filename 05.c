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
    int end=0;// 陣列結尾
    while(N--){
        scanf("%d%d",&n,&m);// 把該段時間所需的車數+1
        
        for(int i=n;i<m;i++)
            a[i]++;
        
        if(m>end)end=m;

    }
    int max=0;// 所需車數
    for(int i=0;i<max;i++){
        if(max<a[i])max=a[i];
    }
    printf("%d\n",max);
}