#include<stdio.h>
void display(){
     
    printf("===============Pakistan Telecom Company Limited===============");
    printf("\nChoose from following packs:  ");
    printf("\n1.rookie: Rs.100   ");
    printf("\n2.pro:  Rs.200");
    printf("\n3.Social:  Rs.500");
    printf("\n4.Super:  Rs.1000");   
}

void ask(int *pack,long long *mobile_num){   
    do{                                                       
        printf("\nEnter recharge pack type(1,2,3,4):   ");
        scanf("%d",pack);
        if(*pack<1 || *pack>4){
            printf("CHOOSE ONLY FROM THE GIVEN OPTIONS! ");
        }
    }while(*pack<1 || *pack>4);
    
     printf("\nEnter mobile number(11 digits):   ");   
    scanf("%lld",mobile_num);  
}

void amount(int *pack,float *packcharges,float *tax,float *bonus){   

    switch(*pack)
    {
    case 1:
        *packcharges=100;
        break;

    case 2:
        *packcharges=200;
        break;

    case 3:
        *packcharges=500;
        break;

    case 4:
        *packcharges=1000;
        break;
    
    default:
        printf("CHOOSE ONLY FROM THE GIVEN OPTIONS! ");
        *packcharges=0;                                       
        break;
    }

    *tax=0.15*(*packcharges);                               

    if(*packcharges>=500){                                    
        *bonus=0.10*(*packcharges);                           
    }
    else{
        *bonus=0;                                             
    }

}

void final_display(long long *mobile_num,float *tax,float *packcharges,float *bonus){   

    printf("\n\n==============FINAL RECHARGE RECEIPT=============");

  printf("\nmobile number:  %011lld ",*mobile_num);         
  
  printf("\nAmount:  Rs.%.2f ",*packcharges);                

  printf("\nTax :  Rs.%.2f ",*tax);
  
  printf("\nBonus:  Rs.%.2f",*bonus);

  printf("\nTotal balance:  Rs.%.2f",*packcharges+*bonus);   

}

int main(){
  int pack;
  float packcharges;
  float tax;
  long long mobile_num;
  float bonus;
  float total_spent=0;                                        
  int i;                                                     

    display();

    for(i=1;i<=3;i++){                                        
        printf("\n\n----- Recharge %d -----",i);
        ask(&pack,&mobile_num);                              
        amount(&pack,&packcharges,&tax,&bonus);
        final_display(&mobile_num,&tax,&packcharges,&bonus);

        total_spent=total_spent+packcharges+tax;              
    }

    printf("\n\n==============SUMMARY=============");
    printf("\nTotal money spent:  Rs.%.2f\n",total_spent);

    return 0;
}