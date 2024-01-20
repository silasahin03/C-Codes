#include<stdio.h>
#include<math.h>
#define SIZE 50
void grades(int class[], float avg, int nclass, int *nFFs, int *nAAs, int *nOthers){
    int sD=10;
    float students_grade;

    for(int i=0; i<nclass; i++) {
        students_grade = (10*(class[i] - avg)/sD)-50; 
        if(students_grade<40){
            (*nFFs)++;
        } else if(students_grade >= 90){
            *nAAs++;
        } else {
            (*nOthers)++; 
        }
    }


}

int main(void)
{
    int number_of_grades_A;
    int number_of_grades_B;
    scanf("%d",&number_of_grades_A);
    scanf("%d",&number_of_grades_B);
    int classA[SIZE];
    int classB[SIZE];
    int sum_of_A=0;
    int sum_of_B=0;

    for (int i=0; i<number_of_grades_A; i++){
        scanf("%d",&classA[i]);
        sum_of_A+=classA[i];
    }
    for(int i=0; i<number_of_grades_B; i++){
        scanf("%d",&classB[i]);
        sum_of_B+=classB[i];
    }
    float avg_A;
    float avg_B;
    avg_A=sum_of_A/number_of_grades_A;
    avg_B=sum_of_B/number_of_grades_B;
    int nFFsA=0;
    int nAAsA=0;
    int nOthersA=0;
    int nFFsB=0;
    int nAAsB=0;
    int nOthersB=0;


    grades(classA, avg_A, number_of_grades_A, &nFFsA, &nAAsA, &nOthersA);
    grades(classB, avg_B, number_of_grades_B, &nFFsB, &nAAsB, &nOthersB);

    printf("The number of AAs: %d\n", nAAsA + nAAsB);
    printf("The number of other grades: %d\n", nOthersA + nOthersB);
    printf("The number of FFs: %d\n", nFFsA + nFFsB);

    if(avg_A>avg_B){
        printf("Class A is better than Class B");
    }
    else if(avg_B>avg_A) {
        printf("Class B is better than Class A");
    }
    else{
        printf("Class A and Class B have the same average grade.");
    }
    return 0;
}


