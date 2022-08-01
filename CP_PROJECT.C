#include <stdio.h>
#include <stdlib.h>

struct houses{
float bio_waste;
float plastic_waste;
float electronic_waste;
};

//Entering the Bio-degradable waste,Plastic waste and Electronic waste collected from each house
void in(struct houses *M,int n){
int i;
for(i=0;i<n;i++){
    printf("Enter the Bio-degradable waste collected from house %d in Kgs:",i+1);
scanf("%f",&(M+i)->bio_waste);
printf("Enter the Plastic waste collected from house %d in Kgs:",i+1);
scanf("%f",&(M+i)->plastic_waste);
printf("Enter the Electronic waste collected from house %d in Kgs:",i+1);
scanf("%f",&(M+i)->electronic_waste);
}
}
// Calculating percentage of waste from each category
void percentage(struct houses *M,float sum_bio,float sum_plastic,float sum_electronic,int n){
printf("\n\t\t\t\t PERCENTAGE !\n\n");
float avg;

avg=(sum_electronic+sum_plastic+sum_bio);

printf("\nThe percentage of biodegradable waste in total wastes is :%f",(sum_bio*100)/avg);

if((sum_bio*100)/avg>50.0){
    printf("\n\n\tPercentage of biodegradable waste is more than 50 percent please try to reduce it !!!\n\n");
    
}
printf("\n----------------------------------------------------------\n");
printf("\nThe percentage of plastic waste in total wastes is :%f",(sum_plastic*100)/avg);

if((sum_plastic*100)/avg>50.0){
    printf("\n\n\tPercentage of plastic waste is more than 50 percent please try to reduce it !!!\n\n");
    }
    printf("\n----------------------------------------------------------\n");
printf("\nThe percentage of electronic waste in total wastes is :%f",(sum_electronic*100)/avg);

if((sum_electronic*100)/avg>50.0){
    printf("\n\n\tPercentage of electronic waste is more than 50 percent please try to reduce it !!!\n\n");
 
}
printf("\n----------------------------------------------------------\n");
}

//

void getdetails(struct houses *M,int n){

int i;
for(i=0;i<n;i++){
printf("%d house:\n",i+1);
if((M+i)->bio_waste<=15&&(M+i)->plastic_waste<=10&&(M+i)->electronic_waste<=5){
printf("produces waste which is less than limit which is appreciable\n ");
}
else{
if((M+i)->bio_waste>15){
printf("crosess limit of biodegradable waste\n");
}
if((M+i)->plastic_waste>10){
printf("crosess limit of plastic waste\n");
}
if((M+i)->electronic_waste>5){
printf("crosess limit of electronic waste\n");
}
}

printf("----------------------------------------------------------\n");
}

}
//statistics of the waste collection per area
void statistics(struct houses *M,int n){

//declared i as counter variable for traversing the array
int i;

float sum_bio=0,sum_plastic=0,sum_electronic=0;

/*declared 3 sum variables to store the sum of biodegradable,
plastic and electronic waste produced by all houses*/

/*this loop iterates n times here n is no of houses and in
every iteration it adds sum of previous waste with sum of ith house waste*/

for(i=0;i<n;i++){
sum_bio+=(M+i)->bio_waste;
sum_plastic+=(M+i)->plastic_waste;
sum_electronic+=(M+i)->electronic_waste;

//by the end of the ith iteration we get sum of wastes produced by i houses in the sum variables*/
}

printf("total biodegradable waste:%f\naverage of biodegradable waste:%f\n",sum_bio,sum_bio/n);
printf("total plastic waste:%f\naverage of plastic waste:%f\n",sum_plastic,sum_plastic/n);
printf("total electronic waste:%f\naverage of electronic waste:%f\n",sum_electronic,sum_electronic/n);
printf("total waste:%f\naverage of all wastes:%f\n",(sum_electronic+sum_plastic+sum_bio),(sum_electronic+sum_plastic+sum_bio)/n);

//checking which waste is maximum in three types of categories

if(sum_bio>=sum_plastic&&sum_bio>=sum_electronic)
{
printf("hey!!we have more biodegradable waste \n");
}
if(sum_bio<=sum_plastic&&sum_plastic>=sum_electronic){
printf("hey!!we have more plastic waste \n");
}
if(sum_bio<=sum_electronic&&sum_bio<=sum_electronic){
printf("hey!!we have more electronic waste \n");
}
if(sum_bio/n>15.0){
printf("warning!!!average biodegradable waste exceeds the limit\n");
}
if(sum_plastic/n>10.0){
printf("warning!!!average plastic waste exceeds the limit\n");
}
if(sum_electronic/n>5.0){
printf("warning!!!average plastic waste exceeds the limit\n");
}
int a=-1;
printf("if you want to see detailed statistics of every house press 1: ");
scanf("%d",&a);
if(a==1){
    
getdetails(M,n);
}
percentage(M,sum_bio,sum_plastic,sum_electronic,n);

}
// Calculating processing fee

void processingfee( struct houses *M,int n){

int i,fee=0,fee1=0,fee2=0;
printf("\n\t\t\t\t PROCESSING FEE !\n\n");
for(i=0;i<n;i++){
    //calculating processingfee for biodegradable waste
    // If the biodegradable waste collected is less than 5 kgs.,then there is no processing fee
if((M+i)->bio_waste>=5)
{
if((M+i)->bio_waste>5&&(M+i)->bio_waste<10)
 // If the biodegradable waste collected is less than 10 kgs.and greater than 5kgs.,then there is  processing fee of 50 Rs.
{
fee=fee+10;
}
else if((M+i)->bio_waste>=10&&(M+i)->bio_waste<15){
     // If the biodegradable waste collected is less than 15 kgs.and greater than 10kgs.,then there is  processing fee of 100 Rs.
fee=fee+50;
}
else if((M+i)->bio_waste>=15){
     // If the biodegradable waste collected is  greater than 70kgs.,then there is  processing fee of 200 Rs.
fee=fee+70;
}
}



//calculating processingfee for plastic waste


    // If the plastic waste collected is less than 5 kgs.,then there is no processing fee
if((M+i)->plastic_waste>5)
{
if((M+i)->plastic_waste>=5&&(M+i)->plastic_waste<10)
 // If the plastic waste collected is less than 10 kgs.and greater than 5kgs.,then there is  processing fee of 50 Rs.
{
fee1=fee1+10;
}
else if((M+i)->plastic_waste>=10&&(M+i)->plastic_waste<20){
     // If the plastic waste collected is less than 20 kgs.and greater than 10kgs.,then there is  processing fee of 100 Rs.
fee1=fee1+50;
}
else if((M+i)->plastic_waste>=20){
     // If the plastic waste collected is  greater than 20kgs.,then there is  processing fee of 200 Rs.
fee1=fee1+100;
}
}

//calculating processingfee for electronic waste


    // If the electronic waste collected is less than 5kgs.,then there is no processing fee
if((M+i)->electronic_waste>5)
{
if((M+i)->electronic_waste>=5&&(M+i)->electronic_waste<10)
 // If the electronic waste collected is less than 10 kgs.and greater than 5kgs.,then there is  processing fee of 50 Rs.
{
fee2=fee2+10;
}
else if((M+i)->electronic_waste>=10&&(M+i)->electronic_waste<20){
     // If the electronic waste collected is less than 20 kgs.and greater than 15kgs.,then there is  processing fee of 100 Rs.
fee2=fee2+50;
}
else if((M+i)->electronic_waste>=20){
     // If the electronic waste collected is  greater than 20kgs.,then there is  processing fee of 200 Rs.
fee2=fee2+80;
}
}
}
printf("\nTotal fee collected by municipality for Bio-degradable waste alone is:%d\n",fee);
printf("\nTotal fee collected by municipality for plastic waste alone is:%d\n",fee1);
printf("\nTotal fee collected by municipality for electronic_waste alone is:%d\n",fee2);
int f=0;
f=fee+fee1+fee2;
if(f==0)
{
printf("\nNo fee is assigned\n");
}
else
{
printf("\nThe the total earning for the municipality per month in this regard is rs.%d\n",f);
}
}
//Fuction to analyse the expense for managing waste

void expense(float s[],int n){

int k;
scanf("%d",&k);
int fee=0;
if (k>=0 && k<n)
{
if (s[k]>30 && s[k] < 50)
{
fee=50;
}
else if (s[k]>=50 && s[k]<70)
{
fee=100;
}
else if (s[k]>=70)
{
fee=200;
}
}
else {printf("Enter valid house number\n");}
printf("fee:%d\n",fee);

}

// Less waste 

void less(float s[],int n){

int min=s[0];
int i;
for(i=0;i<n;i++){
if(s[i]<min){
min=s[i];
}
}
for(i=0;i<n;i++){
if(min==s[i]){
printf("House number %d produces less waste with quantity %f\n",i+1,s[i]);
}
}

}



int main()
{
     printf("\n\t\t\t\t WASTE MANAGEMENT!\n\n");
FILE *f=fopen("f1","a");
fclose(f);
int b;
int i;

printf("\nIf you want to enter details press 0 or\nIf you want to continue with previous details press any other key: ");
scanf("%d",&b);

int n;
int size;

if(b==0){
    
printf("\nEnter the total number of houses:");
scanf("%d",&n);
f=fopen("f1","w");
putw(n,f);


}
else{
    
FILE *fp;
f=fopen("f1","r");
if(f){
fseek (f, 0, SEEK_END);
size = ftell(f);
if(size==0){
printf("\nSry!!the file is empty");
return 0;
}
else{
fseek (f, 0, SEEK_SET);
}
}else{
printf("\nTry again later there is an error in opening file");
return 0;
}


n=getw(f);
}
struct houses M[n];
if(b==0){
in(M,n);
fwrite(M,sizeof(struct houses),n,f);
}
else{
fread(M,sizeof(struct houses),n,f);
}
float s[n] ;

for(int i=0;i<n;i++)
{
s[i]=(*(M+i)).bio_waste+(*(M+i)).plastic_waste+(*(M+i)).electronic_waste;
}

int a;
do{

int choice;

//Menu-driven program 

printf("\nEnter choice :\nchoice 1: gives statistics of waste collected\nchoice 2:gives info about processing fee\nchoice 3: to know about the house which produces less waste\nchoice 4:Gives info about expense\n");
scanf("%d",&choice);
if(choice==1){
statistics(M,n);
}
else if(choice==2){
processingfee(M,n);
}
else if(choice==3){
less(s,n);
}
else if(choice==4){
expense(s,n);

}

printf("\nIf you want to try again press 0 else press any other key\n");
scanf("%d",&a);

}while(a==0);


return 0;
}
