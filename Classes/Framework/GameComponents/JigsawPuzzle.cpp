#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "JigsawPuzzle.h"

void jigsawPuzzleBuilder(int map[], int vol, int col)
{
	int data[128];

	int maxnumber = vol*col - 1;
	for (int i = 0; i<maxnumber; ++i){
		data[i] = i;
		int replacei = rand() % (i + 1);
		int t = data[i];
		data[i] = data[replacei];
		data[replacei] = t;
	}
	data[maxnumber] = maxnumber;

	int coverPairCount = 0;
	for (int i = 0; i<maxnumber; ++i){
		for (int j = i + 1; j<maxnumber; ++j){
			if (data[i]>data[j])
				coverPairCount++;
		}
	}
	if ((coverPairCount & 1) == 1){
		int t = data[maxnumber - 1];
		data[maxnumber - 1] = data[maxnumber - 2];
		data[maxnumber - 2] = t;
	}

	for (int i = 0; i< maxnumber + 1; ++i){
		map[i] = data[i];
	}
}

