//[C_AR10-中] 新通話費率
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1912
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//不知道為甚麼floor在judge不能用
double flr(double num){
    return (int)num;
}

int main(){
    float mul[4]={0.9,0.8,0.7,0.6};
    int fee[4]={186,386,586,986};
    int plan,sec;
    scanf("%d,%d",&plan,&sec);
    //printf("%d %d\n",plan,sec);
    for(int i=0;i<=4;i++){
        if(fee[i]==plan)
            plan=i;
    }
        
    int cost=flr(sec*mul[plan]*0.1+0.5);//2880

    if(cost<=fee[plan])cost=fee[plan];
    else if(cost-fee[plan]<=fee[plan])cost=flr(cost*mul[plan]+0.5);
    else cost=flr(cost*(mul[plan]-0.1)+0.5);

    printf("%d\n",cost);

}