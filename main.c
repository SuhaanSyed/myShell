#include "main.h"

int main(int argc, char **argv) {
    char *prompt = "[QUASH]$ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    const char *delimiter = " \n";
    char *token = NULL;
    size_t n = 0;
    ssize_t read = 0;
    int num_tokens = 0;
    int i;

    (void)argc;
    printf("Wekcome...\n");

    while (read != -1) {
        printf("%s", prompt);
        read = getline(&lineptr, &n, stdin);
        
        lineptr_copy = malloc(sizeof(char) * read);
        strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delimiter);
        
        while (token != NULL) {
            num_tokens++;
            token = strtok(NULL, delimiter);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delimiter);

        for (i = 0; token!= NULL; i++) {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delimiter);
        }
        argv[i] = NULL;

        printf("%s\n", lineptr);

        for (i = 0; argv[i] != NULL; i++) {
            printf("%s\n", argv[i]);
        }
        free(lineptr);
        free(lineptr_copy);
        free(argv);
    }

    
    return (0);
}
