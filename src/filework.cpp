#include "filework.h"

int random_number(int rand_border)
{
    return (rand() % rand_border);
}

char* take_new_word(char* file_name, int file_length)
{
    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        perror("Error opening file");
        return "ERROR";
    }
    int counter = 0;
    int number_needed = random_number(file_length);
    char* line;
    line = new char[4096];
    char* buf;
    while (!feof(f)) {
        if (fgets(line, 4096, f) > 0 && 0 != strcmp(line, "")) {
            buf = strtok(line, IGNORESYM);
            do {
                if (counter == number_needed) {
                    fclose(f);
                    int j = 0;
                    char character;
                    while (buf[j]) {
                        character = buf[j];
                        buf[j] = (char)tolower(character);
                        j++;
                    }
                    return buf;
                }
                buf = strtok(NULL, IGNORESYM);
                counter++;
            } while (buf);
        }
    }
    fclose(f);
    delete (line);
    return "ERROR";
}

int word_count_definition(char* file_name)
{
    FILE* f = fopen(file_name, "r");
    if (f == NULL) {
        perror("Error opening file");
        return -1;
    }
    int word_count = 0;
    char* line;
    line = new char[4096];
    char* buf;
    while (!feof(f)) {
        if (fgets(line, 4096, f) > 0 && 0 != strcmp(line, "")) {
            buf = strtok(line, " ,.\n");
            do {
                word_count++;
                buf = strtok(NULL, " ,.\n");
            } while (buf);
        }
    }
    fclose(f);
    delete (line);
    return word_count;
}

int file_check(
        char* file_name_easy, char* file_name_normal, char* file_name_hard)
{
    int word_count = word_count_definition(file_name_easy);
    if (word_count < 1) {
        return word_count;
    }
    word_count = word_count_definition(file_name_normal);
    if (word_count < 1) {
        return word_count;
    }
    word_count = word_count_definition(file_name_hard);
    if (word_count < 1) {
        return word_count;
    }
    return 1;
}
