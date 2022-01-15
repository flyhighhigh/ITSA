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

    LINE a[1000],b[1000];
    int idx_a=0,idx_b=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(*(str1+i)==*(str2+j)){//儲存可以連成的線 str1->str2
                a[idx_a].d1=i;
                a[idx_b].d2=j;
                //printf("%d%d\n",i,j);
                idx_a++;
            }
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(*(str2+i)==*(str1+j)){//str2->str1
                a[idx_b].d1=i;
                a[idx_b].d2=j;
                //printf("%d%d\n",i,j);
                idx_b++;
            }
        }
    }
    qsort(a,idx_a,sizeof(LINE),cmp);
    qsort(b,idx_b,sizeof(LINE),cmp);

    //算str1->str2的max
    int max=0;
    for(int i=0;i<idx_a;i++){
        int count=1;
        int base1=a[i].d1;
        int base2=a[i].d2;
        for(int j=i+1;j<idx_a;j++){
            if(a[j].d1>base1 && a[j].d2>base2){
                base1=a[j].d1;
                base2=a[j].d2;
                count++;
            }
        }
        if(count>max)max=count;
    }
    //算str2->str1的max
    for(int i=0;i<idx_b;i++){
        int count=1;
        int base1=b[i].d1;
        int base2=b[i].d2;
        for(int j=i+1;j<idx_b;j++){
            if(b[j].d1>base1 && b[j].d2>base2){
                base1=b[j].d1;
                base2=b[j].d2;
                count++;
            }
        }
        if(count>max)max=count;
    }
    
    printf("%d\n",max);

}
