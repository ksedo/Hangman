#include "draw.h"
#include "filework.h"
#include "misstake.h"

using namespace std;

int misse = 0;
int missm = 0;
int missh = 0;
int endg = 0;

int main()
{
    system("clear");
    setlocale(LC_CTYPE, "");
    srand(time(NULL));

    int check = file_check(WORDSEASY, WORDSNORM, WORDSHARD);
    if (check == 0) {
        cout << "File is empty" << endl;
        return 0;
    }
    if (check == -1) {
        cout << "Could not find file with the desired name" << endl;
        return 0;
    }

    bool game = true;
    int diffic = 1;
    while (game) {
        system("clear");
        char answer_char[256];
        int answer = 0;
        char* righ;
        int false_letters = 0;

        cout <<
        "  _    _ \n" <<
        " | |  | |\n" <<
        " | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __ \n" <<
        " |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n" <<
        " | |  | | (_| | | | | (_| | | | | | | (_| | | | |\n" <<
        " |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n" <<
        "                      __/ |\n" <<
        "                     |___/\n\n";
        cout << "1. Start game" << endl;
        cout << "2. Choose difficulty" << endl;
        cout << "3. Exit" << endl;
        cin >> answer_char;
        answer = atoi(answer_char);

        switch (answer) {
        case 3:
            game = false;
            break;
        case 2:
            system("clear");
            while (true) {
                cout << "Choose difficulty (1-easy, 2-normal, 3-hard)" << endl;
                char diffic_char[256];
                cin >> diffic_char;
                diffic = atoi(diffic_char);
                if (diffic == 1 || diffic == 2 || diffic == 3) {
                    break;
                }
                system("clear");
                cout << "Wrong typed difficulti, try again" << endl;
            }
            break;
        case 1:
            misse = 0;
            missm = 0;
            missh = 0;
            endg = 0;
            false_letters = setdificulty(diffic, &righ);
            bool end = true;
            int fch = 0;
            int misst = 0;
            int right_letters = strlen(righ);
            char flse[false_letters];
            memset(flse, '_', false_letters);
            char mem[right_letters];
            memset(mem, '_', right_letters);
            system("clear");
            hangman_draw(0, 0);
            char sim;
            while (end == true) {
                int check = 0;
                cout << endl << "Enter the intended letter" << endl;
                cin >> sim;
                sim = (char)tolower(sim);
                int existr = 0;
                for (int i = 0; i < right_letters; i++) {
                    if (sim == mem[i]) {
                        existr = 1;
                        word(1,
                             flse,
                             mem,
                             diffic,
                             right_letters,
                             false_letters);
                        cout << "This letter already right." << endl;
                        break;
                    }
                }
                for (int i = 0; i < right_letters; i++) {
                    if ((sim == righ[i]) && (existr == 0)) {
                        misst = misstake(righ, mem, i, right_letters);
                        word(misst,
                             flse,
                             mem,
                             diffic,
                             right_letters,
                             false_letters);
                        check++;
                        break;
                    }
                }
                if ((check == 0) && (fch < false_letters + 1)
                    && (existr == 0)) {
                    int exist = 0;
                    for (int i = 0; i < false_letters; i++) {
                        if (sim == flse[i]) {
                            exist = 1;
                            break;
                        }
                    }
                    if (exist == 1) {
                        word(1,
                             flse,
                             mem,
                             diffic,
                             right_letters,
                             false_letters);
                        cout << "This letter already wrong." << endl;
                    } else {
                        flse[fch] = sim;
                        fch++;
                        word(misst,
                             flse,
                             mem,
                             diffic,
                             right_letters,
                             false_letters);
                    }
                }
                if (misst == 2) {
                    cout << "Game over, you WIN" << endl;
                    end = false;
                }
                if (fch >= false_letters) {
                    cout << "Game over, you LOSE" << endl;
                    cout << "The hidden word: " << righ << endl;
                    end = false;
                }
                misst = 0;
                if (end == false) {
                    char a;
                    cin.clear();
                    while (cin.get() != '\n') {
                    };
                    cout << "Press enter to exit the menu" << endl;
                    a = getchar();
                    system("clear");
                }
            }
            break;
        }
    }
    return 0;
}
