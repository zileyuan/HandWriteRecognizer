#ifndef HWR_LIBRARY_H
#define HWR_LIBRARY_H

#include <string>
#include <vector>

int init(const char* filePath, int width, int height);
int add_point(double x, double y);
int recognize(char **words);
int clear();
void destroy();

#endif //HWR_LIBRARY_H