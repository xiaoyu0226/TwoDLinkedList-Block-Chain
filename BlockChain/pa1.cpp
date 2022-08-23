/**
 * @file pa1.cpp
 * @author your name(s)
 *
 * Contains basic tests for CPSC 221 PA1
 *
 * THIS FILE WILL NOT BE SUBMITTED TO PRAIRIELEARN
 * 
 * IT IS HIGHLY RECOMMENDED TO ADD YOUR OWN TESTS TO THIS FILE!
 * 
 * Think about the mechanical processes in the other functions you have written.
 * Where are the likely places for the logic to go wrong?
 * Write tests that specifically target these potential weak points!
 * START WITH SMALL TEST CASES!
 */

#include "block.h"
#include "twodlinkedlist.h"

#include <iostream>

using namespace std;
using namespace cs221util;

// Declaration of testing functions.
// Recommended to have a testing function for each major function in Block and/or TwoDLinkedList
void TestBlockify();
void TestCheckerSwap();
void TestFlipHorizontal();
void TestNew();

// Entry point to your program
int main(void) {

  // Add or remove calls to the declared testing functions as necessary
  //TestBlockify();
  //TestCheckerSwap();
  //TestFlipHorizontal();
  TestNew();

  return 0;
}

// Implementation of testing functions

/**
 *  Builds a list from an input image, calls Blockify, and renders to a PNG
 */
void TestBlockify() {
  cout << "Entered TestBlockify..." << endl;

  cout << "Reading input image...";
  PNG inputimg;
  inputimg.readFromFile("input-img/cat-face_1f431.png");
  cout << " done." << endl;

  cout << "Creating TwoDLinkedList...";
  TwoDLinkedList catfacelist(inputimg, 40, 40);
  cout << " done." << endl;

  cout << "Calling Blockify on list...";
  catfacelist.Blockify();
  cout << " done." << endl;

  cout << "Rendering blockified image to output PNG...";
  PNG outputimg = catfacelist.Render();
  cout << " done." << endl;

  cout << "Writing blockified PNG to file...";
  outputimg.writeToFile("output-img/cat-face-blockify-40x40.png");
  cout << " done." << endl;

  cout << "Exiting TestBlockify...\n" << endl;
}

void TestNew() {
    cout << "Entered TestBlockify..." << endl;

  cout << "Reading input image...";
  PNG inputimg;
  inputimg.readFromFile("input-img/cat-face_1f431.png");
  cout << " done." << endl;

  cout << "Creating TwoDLinkedList...";
  TwoDLinkedList catfacelist(inputimg, 40, 40);
  cout << " done." << endl;

  cout << "Calling Blockify on list...";
  cout << " done." << endl;

  cout << "Rendering blockified image to output PNG...";
  PNG outputimg = catfacelist.Render();
  cout << " done." << endl;

  cout << "Writing blockified PNG to file...";
  cout << " done." << endl;

  cout << "Exiting TestBlockify...\n" << endl;
}

/**
 *  Builds a list from an input image, calls CheckerSwap, and renders to a PNG
 */
void TestCheckerSwap() {
  cout << "Entered TestCheckerSwap..." << endl;

  cout << "Reading input image...";
  PNG inputimg;
  inputimg.readFromFile("input-img/2017z125-500x400.png");
  cout << " done." << endl;

  cout << "Creating TwoDLinkedList...";
  TwoDLinkedList bikelist(inputimg, 5, 4);
  cout << " done." << endl;

  cout << "Calling CheckerSwap on list...";
  bikelist.CheckerSwap();
  cout << " done." << endl;

  cout << "Rendering checkerswapped image to output PNG...";
  PNG outputimg = bikelist.Render();
  cout << " done." << endl;

  cout << "Writing checkerswapped PNG to file...";
  outputimg.writeToFile("output-img/2017z125-checkerswap-5x4.png");
  cout << " done." << endl;

  cout << "Exiting TestCheckerSwap...\n" << endl;
}

/**
 *  Builds a list from an input image, calls FlipHorizontal, and renders to a PNG
 */
void TestFlipHorizontal() {
  cout << "Entered TestFlipHorizontal..." << endl;

  cout << "Reading input image...";
  PNG inputimg;
  inputimg.readFromFile("input-img/cs-256x224.png");
  cout << " done." << endl;

  cout << "Creating TwoDLinkedList...";
  TwoDLinkedList cslist(inputimg, 8, 4);
  cout << " done." << endl;

  cout << "Calling FlipHorizontal on list...";
  cslist.FlipHorizontal();
  cout << " done." << endl;

  cout << "Rendering flipped image to output PNG...";
  PNG outputimg = cslist.Render();
  cout << " done." << endl;

  cout << "Writing flipped PNG to file...";
  outputimg.writeToFile("output-img/cs-fliphorizontal-8x4.png");
  cout << " done." << endl;

  cout << "Exiting TestFlipHorizontal...\n" << endl;
}