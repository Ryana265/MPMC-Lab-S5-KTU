#include<stdio.h>
int main(){
    int n,i,bt[20],op,ct[10],c,tat[20],wt[20],j,temp,prio[20],qt;
    float twt=0,ttat=0,awt=0,atat=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter the burst time of each process: ");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    do{
        printf("\nEnter the option: ");
        printf("\n1.FCFS\n2.SJF\n3.PRIORITY\n4.ROUNDROBIN\n");
        scanf("%d",&op);
        if(op==1){
            for(i=0;i<n;i++){
                ct[i]=c+bt[i];
                c=ct[i];
                tat[i]=ct[i];
            }
            for(i=0;i<n;i++){
                wt[i]=tat[i]-bt[i];
            }
             printf("gantt chart\n");
             printf("0");
            for(i=0;i<n;i++){
                printf("|p[%d]  %d |",i,tat[i]);
            }
            printf("\n");
            printf("BT\twt\ttat\n");
            for(i=0;i<n;i++){
                printf("%d\t%d\t%d\n",bt[i],wt[i],tat[i]);
            }
            for(i=0;i<n;i++){
                 twt+=wt[i];
                 ttat+=tat[i];
            }
            awt=twt/n;
            atat=ttat/n;
            printf("Average waiting time: %.2f",awt);
            printf("\nAverage TurnAroundTime: %.2f",atat);
        }
        else if(op==2){
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    if(bt[j]>bt[j+1]){
                        temp=bt[j];
                        bt[j]=bt[j+1];
                        bt[j+1]=temp;
                    }
                }
            }
            for(i=0;i<n;i++){
                ct[i]=c+bt[i];
                c=ct[i];
                tat[i]=ct[i];
            }
            for(i=0;i<n;i++){
                wt[i]=tat[i]-bt[i];
            }
            printf("BT\twt\ttat\n");
            for(i=0;i<n;i++){
                printf("%d\t%d\t%d\n",bt[i],wt[i],tat[i]);
            }
            for(i=0;i<n;i++){
                 twt+=wt[i];
                 ttat+=tat[i];
            }
            awt=twt/n;
            atat=ttat/n;
            printf("Average waiting time: %.2f",awt);
            printf("\nAverage TurnAroundTime: %.2f",atat);
        }
        else if(op==3){
            printf("Enter the priority: ");
            for(i=0;i<n;i++){
                scanf("%d",&prio[i]);
            }
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    if(prio[j]>prio[j+1]){
                        temp=bt[j];
                        bt[j]=bt[j+1];
                        bt[j+1]=temp;
                    }
                }
            }
            for(i=0;i<n;i++){
                ct[i]=c+bt[i];
                c=ct[i];
                tat[i]=ct[i];
            }
            for(i=0;i<n;i++){
                wt[i]=tat[i]-bt[i];
            }
            printf("pr\tBT\twt\ttat\n");
            for(i=0;i<n;i++){
                printf("%d\t%d\t%d\t%d\n",prio[i],bt[i],wt[i],tat[i]);
            }
            for(i=0;i<n;i++){
                 twt+=wt[i];
                 ttat+=tat[i];
            }
            awt=twt/n;
            atat=ttat/n;
            printf("Average waiting time: %.2f",awt);
            printf("\nAverage TurnAroundTime: %.2f",atat);
        }
        else if(op==4){
            printf("Enter the quanta time: ");
            scanf("%d",&qt);
            for(i=0;i<n;i++){
                if(bt[i]>=qt){
                    ct[i]=c+bt[i];
                    c=ct[i];
                    tat[i]=ct[i]; 
                }
                else{
                    
                }
            }
            for(i=0;i<n;i++){
                wt[i]=tat[i]-bt[i];
            }
            printf("BT\twt\ttat\n");
            for(i=0;i<n;i++){
                printf("%d\t%d\t%d\n",bt[i],wt[i],tat[i]);
            }
            printf("gantt chart");
            for(i=0;i<n;i++){
                printf("p[%d] %d",n,tat[i]);
            }
            for(i=0;i<n;i++){
                 twt+=wt[i];
                 ttat+=tat[i];
            }
            awt=twt/n;

atat=ttat/n;
            printf("Average waiting time: %.2f",awt);
            printf("\nAverage TurnAroundTime: %.2f",atat);
        }
        else{
            printf("Invalid option!");
        }
    }while(op>4);
    return 0;
}
