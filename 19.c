//[C_AR19-易] 最大連續子序列
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2090
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
    char str[1000],temp[1000],c;
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;){
        scanf("%c",&c);
        if(isdigit(c))str[i++]=c;
    }
    str[len]='\0';
    //printf("--[%s]\n",str);

    int max=0;
    for(int i=1;i<=len;i++){//要取的子序列 長度
        for(int j=0;j<i&&j+i<=len;j++){//從哪裡開始取 不能取超過長度
            for(int k=0;k<i;k++){//現在取到第幾個字
                temp[k]=str[j+k];
            }
            temp[i]='\0';

            if(strstr(str+j+1,temp)!=NULL){//在自己的後面還可以找到一樣的字串
                if(i>max)max=i;
            }
        }
        
    }
    printf("%d\n",max);

}
