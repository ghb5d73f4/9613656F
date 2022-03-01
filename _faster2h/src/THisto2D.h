/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- author: G. Henning -*-
 -*- created: Mon Jan 27 11:16:46 CET 2020 -*-
 -*- copyright: GH/IPHC 2020 -*-
 -*- file:  -*-
 -*- purpose: -*-
 **/

// Creating a c++/C equivalent to python's histo

#ifndef THISTO2D_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;


class THisto2D
{
 public:
  ~THisto2D();
  THisto2D(const int nbinsx, 
         const float xmin, const float xmax,
         const int nbinsy, const float ymin, const float ymax) ;
  
  const void Fill(const float x, const float y, const int w=1);
  const void SaveAs(const char* filepath, 
                    const unsigned int threshold=0);
  const void Dump(const unsigned int threshold=0);

 private:
  int fnbinsx, fnbinsy;
  float fbinwidthx, fbinwidthy;
  float fxmin, fxmax, fymin, fymax;
  unsigned int foutofrange;
  unsigned short int *bins;
};

#define THISTO2D_H
#endif
