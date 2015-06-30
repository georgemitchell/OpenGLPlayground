#ifndef IMAGE_UTILS_H
#define	IMAGE_UTILS_H

bool WriteJpeg( const char * destinationFile, const unsigned char * rgbxBuffer, int width, int height );

// Drop-in replacement for stbi_load_from_memory(), but without component specification.
// Often 2x - 3x faster.
unsigned char * TurboJpegLoadFromMemory( const unsigned char * jpg, const int length, int * width, int * height );

unsigned char * TurboJpegLoadFromFile( const char * filename, int * width, int * height );

#endif // IMAGE_UTILS_H