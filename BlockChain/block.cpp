/**
 * @file block.cpp
 * @author your name(s)
 *
 * Implements a rectangular image portion block for CPSC 221 PA1
 *
 * COMPLETE THE FUNCTION BODIES IN THIS FILE AND SUBMIT TO PRAIRIELEARN
 */

#include "block.h"

/**
 *  Sets the values in the data attribute, based on the w x h pixels rectangular region of sourceimg
 *  with the upper-left corner at (left, upper). The orientation of the pixels in the data vector
 *  must match with the orientation of the pixels in the PNG.
 *
 *  @param w - the width (in pixels) of the rectangular subimage region
 *  @param h - the height (in pixels) of the rectangular subimage region
 *  @param upper - the y-coordinate of the subimage region's upper-left corner
 *  @param left - the x-coordinate of the subimage regions's upper-left corner
 *  @param sourceimg - the input PNG image
 *
 *  @pre upper and left (and upper + h - 1, left + w - 1) are valid vector indices
 *  @post pixels contains sourceimg's pixel data starting from (left, upper)
 */
void Block::Build(unsigned int w, unsigned int h, unsigned int upper, unsigned int left, const PNG& sourceimg) {
  // COMPLETE YOUR IMPLEMENTATION BELOW
  for (unsigned int y = upper; y < upper + h; y++) {
    vector<RGBAPixel> row;
    for (unsigned int x = left; x < left + w; x++) {
      RGBAPixel* pixel = sourceimg.getPixel(x, y);
      row.push_back(*pixel);
    }
    pixels.push_back(row);
  }

}

/**
 *  Writes the pixel color data into the target PNG, starting from (left, upper)
 *
 *  @pre upper, left are valid image indices
 *  @pre the rectangular region beginning at (left, upper) can completely receive all of the data attribute's color
 *  @post target PNG's subimage region has been filled with data attribute's pixel data
 */
void Block::Render(unsigned int upper, unsigned int left, PNG& targetimg) const {
  for (unsigned int y = 0; y < GetHeight(); y++) {
    for (unsigned int x = 0; x < GetWidth(); x++) {
      RGBAPixel* pixel = targetimg.getPixel(x + left, y + upper);
      pixel->r = pixels[y][x].r;
      pixel->g = pixels[y][x].g;
      pixel->b = pixels[y][x].b;
      pixel->a = pixels[y][x].a;
    }
  }
  // COMPLETE YOUR IMPLEMENTATION BELOW

}

/**
 *  Mirror this block's pixel data horizontally (along a vertical axis)
 *
 *  @post pixel data in this Block has been mirrored horizontally
 */
void Block::FlipHorizontal() {
  // COMPLETE YOUR IMPLEMENTATION BELOW
  for (unsigned int y = 0; y < GetHeight(); y++) {
    reverse(pixels[y].begin(), pixels[y].end());
  }
/**
  for (unsigned int y = 0; y < GetHeight(); y++) {
    for (unsigned int x = 0, j = GetWidth() - 1; x < GetWidth(); x++, j--) {
      if (x < GetWidth() / 2) {
        RGBAPixel temp = pixels[y][x];
        pixels[y][x]=pixels[y][j];
        pixels[y][j]=temp;
      }
    }
  }
  */
}

/**
 *  Mirror this block's pixel data vertically (along a horizontal axis)
 *
 *  @post pixel data in this Block has been mirrored vertically
 */
void Block::FlipVertical() {
  // COMPLETE YOUR IMPLEMENTATION BELOW 
  reverse(pixels.begin(), pixels.end());


  /**
  for (unsigned int y = 0, j = GetHeight() - 1; y < GetHeight(); y++, j--) {
    if (y < GetHeight() / 2) {
      vector<RGBAPixel> temp = pixels[y];
      pixels[y]=pixels[j];
      pixels[j]=temp;
    }
  }
  */
}

/**
 *  Returns the width (in pixels) of this Block
 *
 *  @return rectangular Block's width
 */
unsigned int Block::GetWidth() const {
  // REPLACE THE LINE BELOW WITH YOUR IMPLEMENTATION
  if (pixels.size() == 0) {
    return 0;
  }
  return pixels[0].size();
}

/**
 *  Returns the height (in pixels) of this Block
 *
 *  @return rectangular Block's height
 */
unsigned int Block::GetHeight() const {
  // REPLACE THE LINE BELOW WITH YOUR IMPLEMENTATION
  return pixels.size();
}

/**
 *  Returns the average color of this Block, for each color channel.
 *  Use truncation for fractional values.
 *
 *  @return RGBAPixel containing the averaged color of all pixels in the Block
 */
RGBAPixel Block::GetAverageColor() const {
  // REPLACE THE LINE BELOW WITH YOUR IMPLEMENTATION
  unsigned int tol_num = GetHeight() * GetWidth();
  float r = 0;
  float g = 0;
  float b = 0;
  float a = 0;
  for (unsigned int y = 0; y < GetHeight(); y++) {
    for (unsigned int x = 0; x < GetWidth(); x++) {
      r += pixels[y][x].r;
      g += pixels[y][x].g;
      b += pixels[y][x].b;
      a += pixels[y][x].a;  
    }
  }

  r = r / tol_num;
  g = g / tol_num;
  b = b / tol_num;
  a = a / tol_num;
  return RGBAPixel(trunc(r), trunc(g), trunc(b), trunc(a));
}

/**
 *  Overwrites the color of every pixel in this Block with the average color of this Block
 *
 *  @post every pixel in the data attribute contains the average color of the entire Block
 */
void Block::MakeAverage() {
  RGBAPixel ave_pixel = GetAverageColor();
  // COMPLETE YOUR IMPLEMENTATION BELOW
  for (unsigned int y = 0; y < GetHeight(); y++) {
    for (unsigned int x = 0; x < GetWidth(); x++) {
      RGBAPixel* pixel = &pixels[y][x];
      pixel->r = ave_pixel.r;
      pixel->g = ave_pixel.g;
      pixel->b = ave_pixel.b;
      pixel->a = ave_pixel.a; 
    }
  }

}

/**
 *  Swaps the values of two (or more) color channels in every pixel in this Block
 *
 *  @param order - number in the range of [0,5] to specify which channels get swapped
 *  @pre order is a valid number between 0 and 5
 *  @post every pixel has the values of its color channels swapped according to specified order
 *
 *    new channel value ->  R   G   B
 *              order   |
 *    -----------------------------------
 *                0     |   R   B   G     <- old channel values
 *                1     |   G   R   B
 *                2     |   G   B   R
 *                3     |   B   R   G
 *                4     |   B   G   R
 *                5     |   R   G   B  (no change)
 *
 *  Example: order = 2, a pixel's initial RGB values are (1, 2, 3).
 *           After calling SwapChannels(2), the pixel's new RGB values are (2, 3, 1)
 *           and all pixels in this block will have their channel values swapped similarly.
 */
void Block::SwapChannels(unsigned int order) {
  // COMPLETE YOUR IMPLEMENTATION BELOW
  for (unsigned int y = 0; y < GetHeight(); y++) {
    for (unsigned int x = 0; x < GetWidth(); x++) {
      RGBAPixel* pixel = &pixels[y][x];
      unsigned char r = pixel->r;
      unsigned char g = pixel->g;
      unsigned char b = pixel->b;

      if (order == 4) {
        pixel->r = b;
        pixel->b = r;
      } else if (order == 3) {
          pixel->r = b;
          pixel->g = r;
          pixel->b = g;
      } else if (order == 2) {
          pixel->r = g;
          pixel->g = b;
          pixel->b = r;
      } else if (order == 1) {
          pixel->r = g;
          pixel->g = r;        
      } else if (order == 0) {
          pixel->g = b;
          pixel->b = g;
      }
    }
  }
}