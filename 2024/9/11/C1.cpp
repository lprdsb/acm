#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sentence[100005];
    int length;
    int index;
} Sentence;


void insertSortByLength(Sentence sentences[], int count) {
    for(int i = 1; i < count; i++) {
        Sentence temp = sentences[i];
        int j = i - 1;
        while(j >= 0 && sentences[j].length < temp.length) {
            sentences[j + 1] = sentences[j];
            j--;
        }
        sentences[j + 1] = temp;
    }
}


void sortByIndex(Sentence sentences[], int count) {
    for(int i = 1; i < count; i++) {
        Sentence temp = sentences[i];
        int j = i - 1;
        while(j >= 0 && sentences[j].index > temp.index) {
            sentences[j + 1] = sentences[j];
            j--;
        }
        sentences[j + 1] = temp;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    Sentence sentences[25];
    int senCount = 0;
    int totalCount = 0;
    char input[100005];


    while(fgets(input, 100005, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "") == 0) {
            break;
        }

        int currentLength = strlen(input);

        if(senCount < 20) {

            strcpy(sentences[senCount].sentence, input);
            sentences[senCount].length = currentLength;
            sentences[senCount].index = totalCount;
            senCount++;
        }
        else {

            insertSortByLength(sentences, senCount);
            if(currentLength > sentences[19].length) {

                strcpy(sentences[19].sentence, input);
                sentences[19].length = currentLength;
                sentences[19].index = totalCount;
            }
        }

        totalCount++;
    }


    sortByIndex(sentences, senCount);


    for(int i = 0; i < senCount; i++) {
        printf("%s\n", sentences[i].sentence);
    }

    return 0;
}
