#include <stdio.h>

int main() {
    int p[20],bt[20],wt[20],tat[20],i,n,k,temp;
    float wtavg,tatavg;
    printf("enetr no of processes :");
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        p[i]=i;
        printf("eneter brust time for each process %d--",i);
        scanf("%d",&bt[i]);
    }
    for( i=0;i<n;i++)
    {
        for( k=i+1;k<n;k++)
        if(bt[i]>bt[k])
        {
             temp=bt[i];
            bt[i]=bt[k];
            bt[k]=temp;
             temp=p[i];
            p[i]=p[k];
            p[k]=temp;
            
        }
    }
    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg=wtavg+wt[i];
        tatavg=tatavg+tat[i];
    }
    printf("\n\tprocess\t\tbrust time\t\t waiting timr\t\t tuen around ttime");
    for(i=0;i<n;i++)
    {
        printf("\n\t\tp%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]/n);
    }
    printf("averafe --%f",wtavg/n);
    printf("average --%f",tatavg/n);
}
