#ifndef G2048_H
#define G2048_H
#include<graphics.h>
#include<iostream>
#include<time.h>

void left();
void right();
void up();
void down();
color_t numCol(int num);
inline void board();
void create();
void G2048();

#endif