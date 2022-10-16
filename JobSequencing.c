// Job Sequencing
#include <stdio.h>
int main(){
    int num,temp,slots,c=0,tp=0,profit[20],deadline[20],slot[10]={0},job[20];
    printf("Enter the number of jobs : ");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
    printf("Enter profit %d and its deadline : ",i);
    scanf("%d%d",&profit[i],&deadline[i]);
    job[i]=i;
    }
    for(int i=1;i<=num-1;i++){
        for(int j=i+1;j<=num;j++){
            if(profit[i]<profit[j]){
                temp=job[j];
                job[j]=job[i];
                job[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;

                temp=deadline[j];
                deadline[j]=deadline[i];
                deadline[i]=temp;
            }
        }
    }
    slots=0;
    for(int i=1;i<=num;i++){

        if(slots<deadline[i]){
            slots=deadline[i];
        }
    }
    for(int i=1;i<=num;i++){
        printf("Job%d : Profit : %d Deadline : %d\n",job[i],profit[i],deadline[i]);
    }
    for(int i=1;i<=num;i++){
        for(int j=deadline[i];j>=1;j--){
            if(slot[j]==0){
                slot[j]=job[i];
                c++;
                tp=tp+profit[i];
                break;
            }
        }
        if(c==slots)
        break;
    }
    printf("The job sequence is : ");
    for(int i=1;i<=slots;i++)
    {
        if(slot[i]!=0)
        printf("--->%d",slot[i]);
    }
    printf("\nMaximum profit : %d",tp);
}