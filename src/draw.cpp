#include "draw.h"

void hangman_draw(int misstakes, int difficulty)
{
    string hangman[11]
            = {"\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "___________________\n"
               "|                |",

               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|         |       \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|        /         \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|        / \\      \n"
               "|                  \n"
               "|                  \n"
               "___________________\n"
               "|                |",

               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "__________________"};

    switch (difficulty) {
    case 1:

        if (misstakes > 0)
            misse++;
        if (misse > 10) {
            misse = 0;
            break;
        }
        if (misse != 0)
            cout << hangman[misse - 1] << endl;
        break;
    case 2:

        if (misstakes > 0)
            missm += 2;
        if (missm == 10) {
            missm -= 1;
        }
        if (missm > 9) {
            missm = 0;
            break;
        }

        if (missm != 0)
            cout << hangman[missm] << endl;
        break;
    case 3:

        if (misstakes > 0)
            missh += 3;
        if (missh > 9) {
            missh = 0;
            break;
        }
        if (missh != 0)
            cout << hangman[missh] << endl;
        break;
    }

    if ((misse == 0) && (missm == 0) && (missh == 0))
        cout << hangman[10] << endl;
}
