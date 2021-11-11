#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for rand()
//#include <stdbool.h>

int callQst(){
                float r1, r2;
                r1 = rand()*0.001;
                r2 = rand()*0.001;
                printf("\n is %f less than %f ? \nEnter your response : \n 1 for true or 0 for false \n", r1, r2);

                return (r1 < r2);
}

void summaryAnswers(int ansArray[], int arrLength){
//    printf("%d", sizeof(ansArray)/sizeof(int));
//    for(int i = 1; i <= (sizeof(ansArray)/sizeof(*ansArray)); i++){
//        printf("\n Your response to %d question was 1(true) 0(false): %d", i, ansArray[i - 0]);
// the above doesnt work as expected ?
    for(int i = 1; i <= arrLength; i++){
       printf("\n Your response to %d question was 1(true) 0(false): %d", i, ansArray[i - 0]);
    }
}

void main(){
   srand(time(0));
    int score = 0;
////    bool Evaluation = false;
    int i = 1; //init du boucle
    int qstNum = 4; //num of questions
    int answer [qstNum];
//    initializeArray(answer);

    for(i = 1; i <= qstNum; i++){

        printf("\n QST %d : ", i);
        int repCorrect = callQst();   // if r1 > r2 then add 1 point to score
        scanf(" %d", &answer[i - 1]);
        if(answer[i - 1] == repCorrect){
                printf("\nRéponse correcte BRAVO!");
                score += 1;
                }
        else { printf("\nRéponse incorrecte :(");
            }
    }

    summaryAnswers(answer, qstNum);

    printf("\n\t Your results are %d pts ", score);
}
