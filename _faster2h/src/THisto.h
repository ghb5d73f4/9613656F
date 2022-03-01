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

#ifndef THISTO_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


class THisto
{
 public:
  ~THisto();
  THisto(const int nbins,
         const float xmin, 
         const float xmax) ;
  
  const void Fill(const float x, const int w=1);
  const void SaveAs(const char* filepath, 
                    const unsigned int threshold=0);
  const void Dump(const unsigned int threshold=0);

 private:
  int fnbins;
  float fbinwidth;
  float fxmin, fxmax;
  unsigned int foutofrange;
  unsigned long int *bins;

};

#define THISTO_H
#endif
