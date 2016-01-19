#ifndef _CHINESEWORD_H_
#define _CHINESEWORD_H_
#include <string>

#include "CocosHead.h"

static ValueVector txt_vec = FileUtils::getInstance()->getValueVectorFromFile("ChineseWords.xml");

string ChineseWord(const char* wordId);

#endif