//[C_AR18-易] 題目配對
//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=1082
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int d1,d2;
}LINE;

int cmp(const void *a,const void *b){
    if((*(LINE*)a).d1>(*(LINE*)b).d1)return 1;
    else if( (*(LINE*)a).d1 == (*(LINE*)b).d1 && (*(LINE*)a).d2 > (*(LINE*)b).d2 )return 1;
    else return -1;
}
int main() {
    char str1[1000], str2[1000];
    int N,M;
    scanf("%d%d%s%s",&N,&M,str1,str2);

    LINE a[1000];
    int idx=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(*(str1+i)==*(str2+j)){//儲存可以連成的線 且d1要是小的那一個
                if(j>=i){
                    a[idx].d1=i;
                    a[idx].d2=j;
                }
                else{
                    a[idx].d1=j;
                    a[idx].d2=i;
                }
                idx++;
            }
        }
    }
    
    qsort(a,idx,sizeof(LINE),cmp);
    // for(int i=0;i<idx;i++){
    //     printf("-- %d %d\n",a[i].d1,a[i].d2);
    // }

    int max=0;
    for(int i=0;i<idx;i++){
        int count=1;
        int base1=a[i].d1;
        int base2=a[i].d2;
        for(int j=i+1;j<idx;j++){
            if(a[j].d1>base1 && a[j].d2>base2){
                base1=a[j].d1;
                base2=a[j].d2;
                count++;
            }
        }
        if(count>max)max=count;
    }
    printf("%d\n",max);
    return 0;


}
