#include "library.h"

#include <iostream>
#include "hand_write_recognizer.h"

using namespace HandWriteRecognizer;

int strokeId = 1;
HandWriteRecognizer::Character* character = NULL;
HandWriteRecognizer::Recognizer* recognizer = NULL;


int init(const char* file_path, int width, int height) {
    if (recognizer == NULL) {
        recognizer = new Recognizer();
    }
    if (recognizer) {
        if (recognizer->loadModelFile(file_path)) {
            character->initSize(width, height);
            return 0;
        }
        return 2;
    }
    return 1;
}

int add_point(double x, double y) {
    if (character) {
        if (character->addPoint(strokeId, x, y)) {
            return 0;
        }
        return 2;
    }
    return 1;
}

int recognize(char **words) {
    if (recognizer && character) {
        std::vector<std::string> resultWords;
        if (recognizer->recognize(*character, resultWords, 10)) {
            for(int i = 0; i < resultWords.size(); i++){
                words[i] = (char *)resultWords[i].c_str();
            }
            return 0;
        }
        return 2;
    }
    return 1;
}

int clear() {
    if (character) {
        character->clear();
        strokeId++;
        return 0;
    }
    return 1;
}

void destroy() {
    if (character) {
        delete character;
        character = NULL;
    }
    if (recognizer) {
        delete recognizer;
        recognizer = NULL;
    }
}