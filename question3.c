#include<stdio.h>
void display(){
     
    printf("===============BUS TERMINAL===============");
    printf("\n");
    printf("\n1.Karachi to Hyderabad: Rs.800   ");
    printf("\n2.Karachi to Sukkur:  Rs.2200");
     printf("\n3.Karachi to Multan : Rs.3500");
 
}

void ask(int *route,int *num_seats,int *fare,char *seat_type){   
    printf("\nEnter Route number(1,2,3):   ");
    scanf("%d",route);                
     if(*route==1){
       *fare=800;            
    }
     else if(*route==2){              
       *fare=2200;   
    }
    else if(*route==3){
       *fare=3500;   
    }

    printf("\nEnter number of seats(1-6) :   ");
    scanf("%d",num_seats);       
    
     printf("\nE.Seat: Economy  ");                                
    printf("\nB.Seat: Business ");
     printf("\nChoose Seat type(E/B) :   ");
     scanf(" %c",seat_type);                                     
    
}

void totalfare(float *final_fare,int *fare,int *num_seats,int *route,char *seat_type ){   
     if(*route==1){
        *final_fare=*num_seats*800;
     }
     else if(*route==2){
         *final_fare=*num_seats*2200;

     }
     else if(*route==3){
        *final_fare=*num_seats*3500;
     }

    float business=0.30*(*final_fare);
     if(*seat_type=='B' || *seat_type=='b'){                      
        *final_fare=*final_fare+business;
     }

}

void final_display(int *route,int *num_seats,char *seat_type,float *final_fare){   

    printf("\n\n==============TICKET=============");

    if(*route==1){
        printf("\nRoute: Karachi to Hyderabad");
    }
    else if(*route==2){
        printf("\nRoute: Karachi to Sukkur");
    }
    else if(*route==3){
        printf("\nRoute: Karachi to Multan");
    }

    printf("\nSeats: %d",*num_seats);

    if(*seat_type=='E' || *seat_type=='e'){                 
        printf("\nSeat type: Economy");
    }
    else if(*seat_type=='B' || *seat_type=='b'){         
        printf("\nSeat type: Business");
    }

    printf("\nFinal fare: Rs. %.2f\n",*final_fare);
}


int main(){

    int route;
    int fare;
    int num_seats;
    float final_fare;
    char seat_type;                                             

    display();
    
    ask(&route,&num_seats,&fare,&seat_type);
     
    totalfare(&final_fare,&fare,&num_seats,&route,&seat_type);

    final_display(&route,&num_seats,&seat_type,&final_fare);

    return 0;
}