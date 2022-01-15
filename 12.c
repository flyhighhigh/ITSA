//[C_AR12-易] 遊樂園的摩天輪
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1939
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    int N,l,r,p;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d",&l,&r,&p);

        int a[120]={0};
        int ptr=1;

        for(int i=1;i<p;i++){
            //i=第幾個人
            if(i%2){
                int count=0;
                while(count<r){
                    ptr++;
                    if(ptr>p)ptr-=p;
                    if(a[ptr]==1)continue;
                    else count++;
                }
                a[ptr]=1;//下去
            }
            else{
                int count=0;
                while(count<l){
                    ptr--;
                    if(ptr==0)ptr+=p;
                    if(a[ptr]==1)continue;
                    else count++;
                }
                a[ptr]=1;//下去
            }
        }
        for(int k=1;k<=p;k++){
            if(a[k]==0){
                printf("%d\n",k);
                break;
            }
        }
    }

}