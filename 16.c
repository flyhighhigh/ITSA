//[C_AR16-易] 統一發票對獎
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2015
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    long long int a[8],n;

    scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3]);
    scanf("%lld",&n);

    long long int num;
    int count[10]={0};
    long long int money=0;
    while(n--){
        int no=1;
        scanf("%lld",&num);
        if(num==a[0]){//特別
            count[0]++;
            money+=2000000;
            no=0;
        }
        for(int i=1;i<=3&&no;i++){//頭獎
            if(num==a[i]){
                count[1]++;
                money+=200000;
                no=0;
                break;
            }
        }
        for(int i=1;i<=3&&no;i++){//二獎
            if(num%10000000==a[i]%10000000){
                count[2]++;
                money+=40000;
                no=0;
                break;
            }
        }
        for(int i=1;i<=3&&no;i++){//三獎
            if(num%1000000==a[i]%1000000){
                count[3]++;
                money+=10000;
                no=0;
                break;
            }
        }
        for(int i=1;i<=3&&no;i++){//四獎
            if(num%100000==a[i]%100000){
                count[4]++;
                money+=4000;
                no=0;
                break;
            }
        }
        for(int i=1;i<=3&&no;i++){//五獎
            if(num%10000==a[i]%10000){
                count[5]++;
                money+=1000;
                no=0;
                break;
            }
        }
        for(int i=1;i<=3&&no;i++){//六獎
            if(num%1000==a[i]%1000){
                count[6]++;
                money+=200;
                no=0;
                break;
            }
        }
        

    }
    for(int i=0;i<7;i++){
        printf("%d",count[i]);
        if(i!=6)printf(" ");
    }
    printf("\n%lld\n",money);
}