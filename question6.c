#include<stdio.h>
#include<stdlib.h>


int main(){
  int days;
  printf("Enter number of days(1 to 10):   ");
  scanf("%d",&days);
                while (days<1  || days>10)
                {
                    scanf("%d",&days);
                }
                
            

    double *temperature = (double*)malloc(days * sizeof(double));
       
   
        
         for(int i=0;i<days;i++){
                   printf("\nEnter values of temperature(-10 to 55 only) day#%d:   ",i+1);
                   scanf("%lf",&temperature[i]);

                   while (temperature[i]<-10 || temperature[i]>55)
                   {
                     scanf("%lf",&temperature[i]);
                   }
                   
         }
      
         for(int i=0;i<days;i++){
            printf("\nDay#%d : %.2lf at address %p",i+1,temperature[i],&temperature[i]);

         }
       double *ptr = temperature;

       double hottest=*ptr;
      double coldest=*ptr;
      int count=0;

         for(int i=0;i<days;i++){

            if(*ptr>hottest){
                   hottest=*ptr;
            }
            else if(*ptr<coldest){
                coldest=*ptr;
            }

            ptr++;
         }
           
      
          for(int i=0;i<days;i++){
            if(temperature[i]>40){
                count++;

            }
          }
           printf("\nNumber of days that are hotter than 40:  %d ",count);


      free(temperature); 
      temperature = NULL;
      printf("\nMemory is released!");
}