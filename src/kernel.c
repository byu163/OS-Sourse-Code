
typedef unsigned long long size_t;

typedef struct{
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
} Framebuffer;

typedef struct {
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

typedef struct {
	PSF1_HEADER* PSF1_Header;
	void* glyphBuffer;
} PSF1_FONT;

void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int color, char chr, unsigned int xOff, unsigned int yOff);

void _start(Framebuffer* framebuffer, PSF1_FONT* psf1_font){
    
	putChar(framebuffer, psf1_font, 0xffffffff, 'G', 10, 10);
    return ;
}

void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int color, char chr, unsigned int xOff, unsigned int yOff)
{
	unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
	char* fontPtr = psf1_font->glyphBuffer + (chr * psf1_font->PSF1_Header->charsize);
	for (unsigned long y = yOff; y < yOff + 16; y++){
		for(unsigned long x = xOff; x < xOff+8; x++){
			if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
				*(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanLine)) = color;
			}
			fontPtr++;
		}
	}
}
