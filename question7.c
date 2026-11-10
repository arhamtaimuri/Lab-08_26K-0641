#include<stdio.h>


int findmax(int *p, int n){
    int max = p[0];

    for(int i=0; i<n; i++){
        if(p[i] > max){
            max = p[i];
        }
    }
    return max;
}

int findmin(int *p, int n){
    int min = p[0];

    for(int i=0; i<n; i++){
        if(p[i] < min){
            min = p[i];
        }
    }
    return min;
}

double findAverage(int *p, int n){
    double avg;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += p[i];
    }

    avg = (double)sum / n;
    return avg;
}

int countAbove(int *p, int n, double avg){
    int count = 0;

    for(int i=0; i<n; i++){
        if(p[i] > avg){
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n){
    int *start = p;
    int *end = p+n-1;
    int temp;

    for(int i=0; i<n/2; i++){
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key){

    for(int i=0; i<n; i++){
        if(key==p[i]){
            return i;
        }
    }

    return -1;
}

int main(){

    int n = 10;
    int marks[n];
    double average;
    int pass = 0;
    int key;

    for(int i=0; i<10; i++){
        printf("Enter marks of student%d: ", i+1);
        scanf("%d", &marks[i]);

        while(marks[i]<0 || marks[i]>100){
            printf("Invalid marks! Enter again: ");
            scanf("%d", &marks[i]);
        }
    }

    printf("\nArray before reversing: ");

    for(int i=0; i<n; i++){
        printf("%d ", marks[i]);

        if(marks[i]>=40){
            pass++;
        }
    }

    printf("\nMaximum marks: %d", findmax(marks,n));

    printf("\nMinimum marks: %d", findmin(marks,n));

    average = findAverage(marks,n);
    printf("\nAverage marks: %.2f", average);

    printf("\nStudents above average: %d",
           countAbove(marks,n,average));

    printf("\nTotal students passed: %d", pass);

    printf("\nEnter which marks you want to search for: ");
    scanf("%d", &key);

    int search = searchMark(marks,n,key);

    if(search != -1){
        printf("Marks found at position: %d", search+1);
    }
    else{
        printf("Marks not found!");
    }

    reverseArray(marks,n);

    printf("\nArray after reversing: ");

    for(int i=0; i<n; i++){
        printf("%d ", marks[i]);
    }

    return 0;
}