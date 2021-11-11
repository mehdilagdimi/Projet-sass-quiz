#include <stdio.h>
#include <stdlib.h> // for rand()
//#include <string.h>
//#include <stdbool.h>

int callQsts1(){
                float r1, r2;
                r1 = rand()*0.001;
                r2 = rand()*0.001;
                printf("\nIs %f less than %f ? \nEnter your response : \n 1 for true or 0 for false \n", r1, r2);

                return (r1 < r2);
}
//callQsts2 can be used for pre-defined qsts,  switch statement is used
int callQsts2(int i) {
    switch (i)
        {
            case 1: printf("question 1 here : \n1.First choice : *** \n2.Second choice : ***");
                    return 1;  //remplace 1 with correct choice
            case 2: printf("qst 2 here: ");
                    return 2;
            case 3: printf("qst 3 here :");
                    return 1;
            case 4 : printf("qst 4 here");
                    return 2;
        }

}

void summaryAnswers(int ansArray[], int arrLength){
//    printf("%d", sizeof(ansArray)/sizeof(int));
//    for(int i = 1; i <= (sizeof(ansArray)/sizeof(*ansArray)); i++){
//        printf("\n Your response to %d question was 1(true) 0(false): %d", i, ansArray[i - 0]);
// the above doesnt work as expected ?
    for(int i = 1; i <= arrLength; i++){
       printf("\n Your response to %d question was 1(true) 0(false): %d", i, ansArray[i - 1]);
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
//      First approach to list questions : using callsQsts1
        int repCorrect = callQsts1();   // if r1 > r2 then add 1 point to score, we can use callQsts directly inside the next if statement

//      Second approch for running quiz using callQsts2
//      int repCorrect = callQsts2(i);

        scanf(" %d", &answer[i - 1]);
//        if(answer[i - 1] == repCorrect){
//                printf("\nRéponse correcte BRAVO!");
//                score += 3;
//                }
//        else {
//                printf("\nRéponse incorrecte :(");
//            }

        while((answer[i - 1]) != repCorrect){
            printf("\n Réponse incorrecte :(, try again");
            score--;
            repCorrect = callQsts1();
//            if(repCorrect) { break;};
            scanf(" %d", &answer[i - 1]);

            if (score == -2){ break;}
        }
        if(answer[i - 1] == repCorrect){
            printf("\n Réponse correcte BRAVO!");
            score += 3;
            }
    }

    summaryAnswers(answer, qstNum);
    if(score < 0) { score = 0;}
    printf("\n\t Your results are %d pts ", score);
}
