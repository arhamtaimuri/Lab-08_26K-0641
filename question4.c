#include<stdio.h>
void display(){
     
    printf("===============Taxi Company===============");
    printf("\nFARE RULES:  ");
    printf("\nBase Fare: Rs.150   ");
    printf("\nFor First 10km:  Rs.60 per km");
     printf("\nAfter 10km : Rs.45 per km");           
 
}

void ask(int *distance,int *waiting_time,float *fare,int *hour,float *night_charge){   
    printf("\nEnter distance in km(0-200):   ");
    scanf("%d",distance);  
    
     printf("\nEnter waiting time in minutes(0-120):   ");   
    scanf("%d",waiting_time);  
     if(*distance<=10){
       *fare=150+(60*(*distance));            
    }
     else if(*distance>10){              
       *fare=150+(60*10)+(45*(*distance-10));  
    }

     int time;

    if (*waiting_time>5)
    {
       time =10*(*waiting_time-5);              
       *fare=*fare+time;
    }
     
    printf("\nEnter hour (0-23):   ");
    scanf("%d",hour); 
       
    if (*hour>=22 || *hour<6)                   
    {
      *night_charge=0.25*(*fare);
       *fare=*fare+*night_charge;
    }   
                                   
}

void final_display(int *distance,int *waiting_time,float *fare){   

    printf("\n\n==============TRIP RECEIPT=============");

  printf("\nDistance Covered:  %d km",*distance);
  
  printf("\nWaiting time :  %d minutes",*waiting_time);
  
  printf("\nTotal Fare:  Rs.%.2f",*fare);

}



int main(){
   int distance;
   int waiting_time;
   float fare;
   int hour;
   float night_charge;
   float total_earnings=0;                     
   float highest_fare=0;                        
   int i;                                     

    display();

    for(i=1;i<=3;i++){                       
        printf("\n\n----- Trip %d -----",i);
        ask(&distance,&waiting_time,&fare,&hour,&night_charge);
        final_display(&distance,&waiting_time,&fare);

        total_earnings=total_earnings+fare;    
        if(fare>highest_fare){                 
            highest_fare=fare;
        }
    }

    printf("\n\n==============DAY SUMMARY=============");
    printf("\nTotal Earnings:  Rs.%.2f",total_earnings);
    printf("\nHighest Fare:  Rs.%.2f\n",highest_fare);

    return 0;
}