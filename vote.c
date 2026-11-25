#include<stdio.h>
#include<string.h>
struct record{
    int voterid;
    char name[50];
    int age;
    int hasvoted;
};
struct record voters[100];
int votercount=0;
void registervoter();
void candidatelist();
void voting();
void winner();
void showsummary();
char candidates[5][50]={
    "marie curie",
    "shinosuke nohara",
    "ai haibara",
    "shinichi kudo",
    "hermonie granger"
};
int votes[5]={0,0,0,0,0};//to preseve vote of that 5 ppls1
int main(){
    int choice;
    do{
        printf("\n****WELCOME TO THE VOTING SYSTEM****\n");
        printf("1. Register as voter\n");
        printf("2.candidate list \n");
        printf("3.cast vote \n");
        printf("4.see winner\n");
        printf("5.exit \n");
        printf("enter u r choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            registervoter();
            break;
            case 2:
            candidatelist();
           break;
           case 3:
           voting();
           break;
           case 4:
           winner();
           break;
           case 5:
           showsummary();
           printf("exiting from the voting system\n");
           break;
           default:
            printf("invalid choice !!!!\n");
        }
    }while(choice!=5);
    return 0;
}
void registervoter(){
    struct record v;
    FILE *fp;
    static int id=1000;
    printf("pls enter u r age ");
    scanf("%d",&v.age);
    if(v.age<18){
        printf("u r not elligble for voting \n");
        return;
    }
    printf("enter name: ");
    scanf(" %49[^\n]", v.name);
    v.voterid=id;
    id++;
    v.hasvoted=0;
    fp=fopen("voters.txt","a");
    if(fp==NULL){
        printf("file error occured ");
        return;
    }
    fprintf(fp," %d|%s|%d|%d \n",v.voterid,v.name,v.age,v.hasvoted);
    fclose(fp);
    voters[votercount] = v;//inserting the data of voters into the struct
    votercount++;
    printf("wow registration successful!!!\n");
    printf("your voter id is %d",v.voterid);
}
void candidatelist(){
    int i;
    printf("\n****CANDIDATE LIST****\n");
    for(i=0;i<5;i++){
        printf("%d|",i+1);
        puts(candidates[i]);
    }
}

void voting()
{
    int enteredid, i, choice;
    int found = 0;
    printf("Enter your voter ID: ");
    scanf("%d", &enteredid);
    for(i = 0; i < votercount; i++)
    {
        if(voters[i].voterid == enteredid)
        {
            found = 1;
            break;//here i value is retained
        }
    }
    if(found == 0)
    {
        printf("Voter not registered\n");
        return;
    }
    if(voters[i].hasvoted == 1)
    {
        printf("You have already voted\n");
        return;
    }
    candidatelist();
    printf("Enter candidate number: ");
    scanf("%d", &choice);
    if(choice < 1 || choice > 5)
    {
        printf("Invalid candidate choice\n");
        return;
    }
    votes[choice - 1]++;
    voters[i].hasvoted = 1;
    printf("Your vote recorded successfully\n");
}
void winner()
{
    int i;
    int max = votes[0];
    int tie = 0;

    for(i = 1; i < 5; i++)
    {
        if(votes[i] > max)
        {
            max = votes[i];
        }}

    printf("\n***** WINNER DECLARATION *****\n");

    if(max == 0)
    {
        printf("No votes have been cast yet\n");
        return;
    }

    for(i = 0; i < 5; i++)
    {
        if(votes[i] == max)
        {
            tie++;
        }
    }

    if(tie > 1)
    {
        printf("Election resulted in a TIE!\n");
        printf("Candidates with equal votes:\n");

        for(i = 0; i < 5; i++)
        {
            if(votes[i] == max)
            {
                printf("%s - %d votes\n", candidates[i], votes[i]);
            }
        }
    }
    else
    { for(i = 0; i < 5; i++) {
            if(votes[i] == max)
            {
                printf("Winner: %s\n", candidates[i]);
                printf("Total votes: %d\n", max);
            }
        }
    }
}
void showsummary(){
    int totalvotes=0;
    float percentage=0;
    for(int i=0;i<5;i++){
        totalvotes+=votes[i];
    }
    printf("\n ELECTION SUMMARY\n");
    printf("\n no of registered voters %d \n",votercount);
    printf("\n ppl who voted %d",totalvotes);
    if(votercount>0){
      percentage =(float)totalvotes*100.0/votercount;
      printf("\n voters turnout %.2f percent \n",percentage);}
     else{
      printf("\n no voters registered \n");}

}