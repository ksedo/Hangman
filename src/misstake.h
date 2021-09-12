#ifndef MISSTAKE_H
#define MISSTAKE_H

#include "draw.h"
#include "filework.h"
#include <iostream>
#include <stdio.h>

using namespace std;

extern int endg;

int setdificulty(int diffic, char** righ);
int misstake(char* righ, char* mem, int i, int r);
void word(int pass, char* flse, char* mem, int diff, int r, int f);

#endif
