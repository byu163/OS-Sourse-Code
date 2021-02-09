#pragma once
#include "math.h"
#include "framebuffer.h"
#include "SimpleFonts.h"

class BasicRenderer{
    public:
    BasicRenderer(Framebuffer* targetFrameBuffer, PSF1_FONT* psf1_Font);
    Point CursorPosition;
    Framebuffer* TargetFrameBuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int Color;
    void Print(const char* str);
    void PutChar(char chr, unsigned int xOff, unsigned int yOff);
};