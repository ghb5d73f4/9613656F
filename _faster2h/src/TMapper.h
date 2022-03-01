/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : June 6th, 2014 -*-
 -*- copyright: GH/IPHC 2014 -*-
 -*- purpose: A mapper object, loading map information from a TNT.map file -*-
 */


#ifndef TMAPPER_H

#include <iostream>
#include <fstream>   
#include <stdio.h>
#include <string.h>
using namespace std;

#include <map>
#include <string>
#include <utility>

class TMapper
{
 public:
  //  TMapper();
  TMapper(const char* mapfile);
  ~TMapper();

  // Control 
  const void DumpMap();
  const int Size() { return (const int) fmap->size();};

  // Access 
  const char* GetChannelName(const int chan);
  const int GetChannelIndex(const int chan);
  const char* GetChannelNameFromIndex(const int index);

  const int KnowThisChannel(const int chan);
  const int KnowThisIndex(const int idx);


 private:

  const void LoadMap(const char* mapfile);
  const void InitMap();

  map<int, string> *fmap;
  map<int, string> *ffromidxmap;
  map<int, int> *fidxmap;
  
};

#define TMAPPER_H
#endif
