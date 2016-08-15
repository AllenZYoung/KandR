#include <stdio.h>
/// 1-14
#define MAX   94
#define BEGIN 32
main(){

    int userInput;
    int freq[MAX] = {0};
    int i, j;

    while((userInput = getchar()) != EOF ){
        if(userInput >= BEGIN && userInput <= BEGIN + MAX){
            if(userInput != '\n'){
                ++freq[userInput-BEGIN];
            }

            if(userInput == '\n'){
                break;
            }
        }
    }

    printf("Case\t|\tFrequencies\n");

    for(i = 0; i < MAX; ++i){
        printf("%c\t|\t%d\n", (i+BEGIN), freq[i]);
    }


  return 0;
}
