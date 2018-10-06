#ifndef DEF_LCSQ
#define DEF_LCSQ DEF_LCSQ

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct sequenceCompart
{
	string SeqA;
	string SeqB;
	string SubSeq;
};

bool readdata(char* filepath,string &sequence);
sequenceCompart setinformation(string sequence);
int** initialization(sequenceCompart information);
int equalstr(char a,char b);
void getmatrix(sequenceCompart information,int ** score);
void backtrack(sequenceCompart &information, int** score, int i, int j);
void getSubSequence(sequenceCompart information);

#endif