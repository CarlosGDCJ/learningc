#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define VERSION "0.0.1"
#define BUFFER_SIZE 512

int main(int argc, char** argv) {

    if (argc < 3)
    {
        fprintf(stderr, "Invalid number of arguments in version %s\n", VERSION);
        exit(1);
    }

    // argv[1] is the file name
    // argv[2] is the category
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Couldn't open file %s\n", argv[1]);
        exit(2);
    }

    char line[BUFFER_SIZE];
    int ids[BUFFER_SIZE];
    int nums_added = 0;

    bool grab_next = false;
    while (fgets(line, sizeof(line), file)) {

        // Strip newline characters
        int line_len = strlen(line);
        if (strcspn(line, "\r\n") != line_len)
            line[strcspn(line, "\r\n")] = '\0';
        else if (strcspn(line, "\n") != line_len)
            line[strcspn(line, "\n")] = '\0';

        if (grab_next && isdigit((unsigned char) line[0]))
        {
            char *curr_char = line;
            while (true)
            {
                if (*curr_char == ',')
                {
                    // If curr_char is a comma, advance
                    curr_char += 1;
                    continue;
                }

                char *end;
                int id = strtol(curr_char, &end, 10);

                if (curr_char == end)
                {
                    break;
                }

                ids[nums_added] = id;
                nums_added++;

                curr_char = end;
            }

            break;
        }

        else if (strcmp(line, argv[2]) == 0) {
            grab_next = true;
        }
    }

    fclose(file);

    // Getting a random index
    srand(time(NULL));

    int rand_idx = rand() % (nums_added + 1 - 0) + 0;
    printf("%d\n", ids[rand_idx]);



    return 0;
}