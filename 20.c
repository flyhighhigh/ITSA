//[C_AR20-易] 檢查數值是否有重複
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2162
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
    int n,idx,flag=1;
    scanf("%d",&n);
    int a[1000]={0};

    for(int i=0;i<n;i++){
        scanf("%d",&idx);
        if(a[idx]==0)a[idx]++;
        else flag=0;
    }
    
    printf("%d\n",flag);

}
