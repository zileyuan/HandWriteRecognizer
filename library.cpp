#include "library.h"

#include <iostream>
#include <numeric>
#include <iterator>
#include <sstream>
#include "hand_write_recognizer.h"
#include "base64.h"

using namespace HandWriteRecognizer;

HandWriteRecognizer::Character* character = NULL;
HandWriteRecognizer::Recognizer* recognizer = NULL;


int hwr_init(const char *model_path, int width, int height) {
    if (recognizer == NULL) {
        recognizer = new Recognizer();
    }
    if (character == NULL) {
        character = new Character();
    }
    if (recognizer && character) {
        if (recognizer->loadModelFile(model_path)) {
            character->initSize(width, height);
            return 0;
        }
        return 2;
    } else {
        hwr_destroy();
    }
    return 1;
}

int hwr_add_point(int strokeId, double x, double y) {
    if (character) {
        if (character->addPoint(strokeId, x, y)) {
            return 0;
        }
        return 2;
    }
    return 1;
}

int hwr_recognize(char *words) {
    if (recognizer && character) {
        std::vector<std::string> resultWords;
        if (recognizer->recognize(*character, resultWords, 10)) {
            std::stringstream ss;
            std::string delimiter=",";
            copy(resultWords.begin(),resultWords.end(), std::ostream_iterator<std::string>(ss, delimiter.c_str()));
            std::string result = ss.str();
            std::string encode_str;
            Base64Base::Encode(result, &encode_str);
            result.copy(words, encode_str.length(), 0);
            words[encode_str.length()] = '\0'; //填充结束符
            return 0;
        }
        return 2;
    }
    return 1;
}

int hwr_clear() {
    if (character) {
        character->clear();
        return 0;
    }
    return 1;
}

void hwr_destroy() {
    if (character) {
        delete character;
        character = NULL;
    }
    if (recognizer) {
        delete recognizer;
        recognizer = NULL;
    }
}