#include<stdio.h>

void display(){
     
    printf("===============AL-SHIFA INTERNATIONAL HOSPITAL===============");
    printf("\n");
    printf("\nRoom Charges:   ");
    printf("\n1.General Ward: Rs. 1500/day");
     printf("\n2.Semi-Private Ward: Rs. 3500/day");
      printf("\n3.Private Ward: Rs. 6000/day");

}

void ask(int *type,int *days_stayed,int *senior_citizen,int *roomcharges){
    printf("\nEnter room type(1,2,3):   ");
    scanf("%d",type);                
     if(*type==1){
       *roomcharges=1500;            
    }
     else if(*type==2){              
       *roomcharges=3500;
    }
    else if(*type==3){
        *roomcharges=6000;
    }

    printf("\nEnter days stayed(1-30) :   ");
    scanf("%d",days_stayed);          

    printf("\nAre you a Senior Citizen?(1/0) :   ");
    scanf("%d",senior_citizen);      
}

void bill(float *initial_bill,int *days_stayed,int *type,float *new_med_bill,int *senior_citizen ){
     if(*type==1){
        *initial_bill=*days_stayed*1500;
     }
     else if(*type==2){
        *initial_bill=*days_stayed*3500;

     }
     else if(*type==3){
        *initial_bill=*days_stayed*6000;
     }

     *initial_bill=*initial_bill+*new_med_bill;
     if(*senior_citizen==1){
        *initial_bill=*initial_bill-1000;
     }
    float discount=0.08*(*initial_bill);   
     if(*days_stayed>=7){
         *initial_bill=*initial_bill-discount;
     }


}

void final_display(int *type,int *days_stayed,int *roomcharges,float *initial_bill){

    printf("==============RECEIPT============= ");

    if(*type==1){
        printf("\nRoom type:  General Ward ");
    }
     else if(*type==2){             
        printf("\nRoom type: Semi-Private Ward ");
    }
    else if(*type==3){
        printf("\nRoom type: Private Ward ");
    }
       printf("\nDays stayed: %d days ",*days_stayed);
       printf("\nRoom charges: Rs.%d/day ",*roomcharges);
       printf("\nFinal bill: Rs.%.2f ",*initial_bill);   
 
} 


int main(){
    float initial_bill;
    int roomcharges;
    display();
    int type;
    int days_stayed;
    int senior_citizen;
    ask(&type,&days_stayed,&senior_citizen,&roomcharges);
   
    int medicine_bill;
    printf("\nEnter medicine bill:   ");
    scanf("%d",&medicine_bill);
    float service_charge=0.5*medicine_bill;
    float new_mediciine_bil=medicine_bill+service_charge;

     bill(&initial_bill,&days_stayed,&type,&new_mediciine_bil,&senior_citizen);  
    
     final_display(&type,&days_stayed,&roomcharges,&initial_bill);
   
    return 0;
}