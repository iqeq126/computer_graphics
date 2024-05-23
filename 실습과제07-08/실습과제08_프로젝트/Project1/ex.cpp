#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
    char sentence[] = "My name is My name My My My cook name";
    char* str = sentence;
    printf("Init string : %s\n----------------Word parsing result-------------\n", str);
    char* answer[sizeof(sentence)];
    int buf = 0, idx = 0, i = 0, j = 0;
    int ansNum[sizeof(sentence)] = {0};
    char* temp = strtok(str, " ");
    while (temp != NULL) {
        if (sizeof(temp) > 0) {
            answer[buf] = temp;
            buf++;
        }
        printf("%s\n", temp);
        temp = strtok(NULL, " ");
    }
    printf("---------------Word count result---------------\n");
    for (i = 0; i < buf; i++) {
        for (j = i; j < buf; j++) {
            if (answer[i] != NULL && answer[j] != NULL ) {
                if (strcmp(answer[i], answer[j]) == 0) {
                    ansNum[idx]++;
                    if(i != j )answer[j] = NULL;
                }
            }
        }
        if (answer[i] != NULL) {
            printf("%s : %d\n", answer[i], ansNum[idx]);
            idx++;
        }
    }
    return 0;
}