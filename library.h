#ifndef HWR_LIBRARY_H
#define HWR_LIBRARY_H

#define DECL_EXPORT __declspec(dllexport)
//#define DECL_EXPORT __attribute__((visibility("default")))

#include <string>
#include <vector>

/**
 * 说明 在载入DLL后进行资源的初始化函数，在整个使用过程中只需要一次
 * 参数 file_path，model文件的路径，请使用hand_write.model的绝对路径
 * 参数 width，画板的宽度
 * 参数 height，画板的高度
 * 返回 0，成功
 * 返回 1，资源异常
 * 返回 2，加载model失败
**/
extern "C" DECL_EXPORT int hwr_init(const char *file_path, int width, int height);

/**
 * 说明 加入笔画的路径点
 * 参数 strokeId，笔画的编号
 * 参数 x，路径点x坐标
 * 参数 y，路径点y坐标
 * 返回 0，成功
 * 返回 1，资源异常
 * 返回 2，加入路径点异常
**/
extern "C" DECL_EXPORT int hwr_add_point(int strokeId, double x, const double y);

/**
 * 说明 识别之前传入的路径点为可能的文字数组
 * 参数 words，传入的字符串数组
 * 返回 0，成功
 * 返回 1，资源异常
 * 返回 2，识别异常
**/
extern "C" DECL_EXPORT int hwr_recognize(char *words);

/**
 * 说明 识别完成一个文字后，清除之前的路径点
 * 返回 0，成功
 * 返回 1，资源异常
**/
extern "C" DECL_EXPORT int hwr_clear();

/**
 * 说明 卸载DLL之前调用，用于清除之前分配的资源
**/
extern "C" DECL_EXPORT void hwr_destroy();

#endif //HWR_LIBRARY_H