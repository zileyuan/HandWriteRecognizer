#include "library.h"

#include <iostream>
#include "hand_write_recognizer.h"

using namespace HandWriteRecognizer;

int strokeId = 1;
HandWriteRecognizer::Character* character = NULL;
HandWriteRecognizer::Recognizer* recognizer = NULL;


int hwr_init(char *file_path, int width, int height) {
    if (recognizer == NULL) {
        recognizer = new Recognizer();
    }
    if (character == NULL) {
        character = new Character();
    }
    if (recognizer && character) {
        if (recognizer->loadModelFile(file_path)) {
            character->initSize(width, height);
            return 0;
        }
        return 2;
    } else {
        hwr_destroy();
    }
    return 1;
}

int hwr_add_point(double x, double y) {
    if (character) {
        if (character->addPoint(strokeId, x, y)) {
            return 0;
        }
        return 2;
    }
    return 1;
}

int hwr_recognize(char **words) {
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

int hwr_clear() {
    if (character) {
        character->clear();
        strokeId++;
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