#include <stdio.h>
#include<stdlib.h>
struct Stud_Rec
{
    char Name[50];
    int Roll_no;
    float Marks;
};

struct Stud_Rec* Read_Rec(void)
{
    struct Stud_Rec* list;
    list=(struct Stud_Rec*)malloc(5*sizeof(struct Stud_Rec));
    int i;
    for(i=0;i<5;i++)
    {
        if (i!=0)
            getchar();
        printf("Enter Names of %d :",i+1);
        scanf("%[\n]",list[i].Name);
        getchar();
        do
        {
            printf("Roll No :");
            scanf("%d",&list[i].Roll_no);
            if(list[i].Roll_no<0)
                printf("Enter Correct\n");
        }while(list[i].Roll_no<0);
        do
        {
            printf("Marks :");
            scanf("%f",&list[i].Marks);
            if(list[i].Marks<0 || list[i].Marks>100)
                printf("Enter Correct\n");
        }while(list[i].Marks<0 || list[i].Marks>100);
        
    }
    printf("Done\n");
    return list;
}
void Write_Rec(struct Stud_Rec *s)
{
    int i;
    printf("Details :\n");
    for(i=0;i<5;i++)
    {
        printf("Student %d:\n",i+1);
        printf("Name : %s\n",s[i].Name);
        printf("Roll No.: %d\n",s[i].Roll_no);
        printf("Marks : %.2f\n",s[i].Marks);
    }
}
int Stud_Count(struct Stud_Rec *s)
{
    int count=0,i;
    float threshold;
    do
    {
        printf("Enter Threshold :");
        scanf("%f",&threshold);
        if(threshold<0 || threshold>100)
            printf("Enter Correct\n");
    }while(threshold<0 || threshold>100);
    for(i=0;i<5;i++)
    {
        if(s[i].Marks>threshold)
            count++;
    }
    return count;
}
void main() {
    int count;
    struct Stud_Count *students; //Do correction, Stud_Rec
    students=Read_Rec();
    Write_Rec(students);
    count=Stud_Count(students);
}