#include<stdio.h>
int main(){
    int i,num;
    printf("Enter the size of the set: ");
    scanf("%d",&num);

    int number[num];

    printf("Enter the elements :");
    for(i=0;i<num;i++){
        scanf("%d",&number[i]);
    }

    printf("Odd Numbers: ");
    for(i=0;i<num;i++){
        if(number[i]%2 !=0){
            printf("%d\t",number[i]);
        }
    }
    printf("\n");

    printf("Even Numbers: ");
    for(i=0;i<num;i++){
        if(number[i]%2 ==0){
            printf("%d\t",number[i]);
        }
    }
    return 0;
    
}
