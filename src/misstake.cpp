#include "misstake.h"

int setdificulty(int diffic, char** righ)
{
    int word_count;
    if (diffic == 1) {
        word_count = word_count_definition(WORDSEASY);
        *righ = take_new_word(WORDSEASY, word_count);
        return 10;
    } else if (diffic == 2) {
        word_count = word_count_definition(WORDSNORM);
        *righ = take_new_word(WORDSNORM, word_count);
        return 5;
    } else if (diffic == 3) {
        word_count = word_count_definition(WORDSHARD);
        *righ = take_new_word(WORDSHARD, word_count);
        return 3;
    } else {
        return 0;
    }
}

int misstake(char* righ, char* mem, int i, int r)
{
    int pass = 0;
    for (int b = 0; b < r; b++) {
        if ((b == i) && (mem[b] == '_')) {
            mem[b] = righ[i];
            endg++;
            for (int c = b + 1; c < r; c++) {
                if ((righ[c] == mem[b]) && (mem[c] == '_')) {
                    mem[c] = righ[c];
                    endg++;
                } else {
                    if (mem[c] == '_')
                        mem[c] = '_';
                }
            }
            pass = 1;
            break;
        }
    }
    if (endg == r) {
        pass = 2;
    }
    return pass;
}

void word(int pass, char* flse, char* mem, int diff, int r, int f)
{
    system("clear");

    if (pass == 0)
        hangman_draw(1, diff);
    if (pass == 1)
        hangman_draw(0, diff);
    cout << "Wrong letters:" << endl;

    for (int b = 0; b < f; b++) {
        cout << flse[b];
    }
    cout << endl;
    cout << "Right letters:" << endl;

    for (int b = 0; b < r; b++) {
        if (mem[b] != ' ')
            cout << mem[b];
    }
    cout << endl;
}
