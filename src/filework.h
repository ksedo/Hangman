#ifndef FILEWORK_H
#define FILEWORK_H

#include <cctype>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDSEASY "files/word1.txt"
#define WORDSNORM "files/word2.txt"
#define WORDSHARD "files/word3.txt"
#define IGNORESYM " ,.\nабвгдеёжзийклмнопрстуфхцчщьыъэюя0123456789"
using namespace std;

int random_number(int rand_border);
char* take_new_word(char* file_name, int file_length);
int word_count_definition(char* file_name);
int file_check(
        char* file_name_easy, char* file_name_normal, char* file_name_hard);

#endif
