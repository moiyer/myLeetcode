#include<iostream>
#define N 200
#define M 10000

using namespace std;

int main(void){
    int n,m,l;
    int trans[N+1]={0},seq[M];
    int seq_len = 0;
    int dp[M];
    int max = 0;
    
    scanf("%d",&n);
    scanf("%d",&m);
    
    for(int i=1;i<=m;i++){
          int tar;
          scanf("%d",&tar);
          
          if(tar <= n )trans[tar] = i;  
    }
    
    scanf("%d",&l);
    for(int j=1;j<=l;j++){
            int temp;
            scanf("%d",&temp);
            
            if(temp <= n && trans[temp]!=0)
            {
                seq[seq_len++] = trans[temp];
            }
    }
    
    for(int k = 0;k < seq_len;k++){
            printf("%d ",seq[k]);
    }
    
    for(int s=0;s<seq_len;s++){
            dp[s] = 1;//从0到s-1的s长度的所求最大值
            for(int r = 0;r < s; r++){
                    if(seq[s]>=seq[r] && (dp[r]+1)>dp[s])dp[s] = dp[r] + 1;
            }
            if(max < dp[s])max = dp[s];
    }
	printf("\n");
	for(int a = 0; a < seq_len; ++a)
		printf("%d ", dp[a]);
	printf("\n");
    printf("%d\n",max);
   
    system("pause");
    return 0;
}