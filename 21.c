//[C_AR021-易] 成績統計
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2196
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

double flr(double num){//judge的floor超怪
    return (int)num;
}
int main() {
    int n;
    double temp;
    double sum[3]={0};
    double total=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
            scanf("%lf",&temp);
            sum[j]+=temp;
            total+=temp;
        }
    
    //用 flr(x*10+0.5)就是對小樹點後第二位四捨五入到第一位
    printf("%.1f ",flr(total/(3*n)*10+0.5)/10);
    for(int j=0;j<3;j++)
        printf(j==2?"%.1f\n":"%.1f ",flr(sum[j]/n*10+0.5)/10);
    
    //不知道為甚麼這樣寫會錯一個 = =
    // printf("%.1f ",total/(3*n));
    // for(int j=0;j<3;j++)
    //     printf(j==2?"%.1f\n":"%.1f ",sum[j]/n);

}
