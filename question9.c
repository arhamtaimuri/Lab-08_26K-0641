
#include<stdio.h>
#include<string.h>

void readMarks(int *m1, int *m2, int *m3){

    printf("\nEnter marks for subject 1: ");
    scanf("%d", m1);

    while(*m1 < 0 || *m1 > 100){
        printf("\nInvalid marks! Enter again: ");
        scanf("%d", m1);
    }

    printf("\nEnter marks for subject 2: ");
    scanf("%d", m2);

    while(*m2 < 0 || *m2 > 100){
        printf("\nInvalid marks! Enter again: ");
        scanf("%d", m2);
    }

    printf("\nEnter marks for subject 3: ");
    scanf("%d", m3);

    while(*m3 < 0 || *m3 > 100){
        printf("\nInvalid marks! Enter again: ");
        scanf("%d", m3);
    }
}

void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest){

    *total = m1 + m2 + m3;
    *average = (double)*total / 3;

    if(m1 >= m2 && m1 >= m3)
        *highest = m1;
    else if(m2 >= m1 && m2 >= m3)
        *highest = m2;
    else
        *highest = m3;

    if(m1 <= m2 && m1 <= m3)
        *lowest = m1;
    else if(m2 <= m1 && m2 <= m3)
        *lowest = m2;
    else
        *lowest = m3;
}

void swapMarks(int *a, int *b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace){

    if(*mark >= 35 && *mark <= 39){

        if(grace > 5)
            grace = 5;

        if(grace > 40 - *mark)
            grace = 40 - *mark;

        *mark = *mark + grace;
    }
}

void findGrade(double avg, char *grade, char *remarks){

    if(avg >= 80){
        *grade = 'A';
        strcpy(remarks, "Excellent");
    }
    else if(avg >= 60){
        *grade = 'B';
        strcpy(remarks, "Good");
    }
    else{
        *grade = 'C';
        strcpy(remarks, "NeedsImprovement!");
    }
}

void incrementByValue(int x){
    x++;
}

void incrementByReference(int *x){
    (*x)++;
}

int main(){

    int m1, m2, m3;
    int total;
    double avg;
    int highest, lowest;

    int a, b;
    int grace = 5;

    int byvalue, byreference;
    char grade;
    char remarks[30];

    printf("STUDENT RESULT CARD REPORT\n");

    printf("\nStudent  Total  Average  Grade  Remarks\n");

    for(int i = 1; i <= 5; i++){

        printf("\n====== Student %d ======\n", i);

        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        calculateStats(m1, m2, m3,
                       &total, &avg, &highest, &lowest);

        if(m1 < m2)
            swapMarks(&m1, &m2);

        if(m1 < m3)
            swapMarks(&m1, &m3);

        if(m2 < m3)
            swapMarks(&m2, &m3);

        findGrade(avg, &grade, remarks);

        printf("\nSorted marks: %d %d %d\n", m1, m2, m3);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);

        printf("%-8d %-7d %-8.2f %-6c %s\n",
               i, total, avg, grade, remarks);
    }


    int x = 5;

    incrementByValue(x);
    byvalue = x;

    printf("After increment by value: %d\n", byvalue); // Due to pass by value we will get the same as it changes only a copy of the original variable.

    incrementByReference(&x);
    byreference = x;

    printf("After increment by reference: %d\n", byreference);
    
    // Pass by reference using a pointer changes the original variable as this time address was passed.

    return 0;
}
