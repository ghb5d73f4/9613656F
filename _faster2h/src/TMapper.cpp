/*
 -*- coding: utf8 -*-
 -*- format: c++ -*-
 -*- author: Greg Henning -*-
 -*- date  : June 6th, 2014 -*-
 -*- copyright: GH/IPHC 2014 -*-
 -*- purpose: A mapper object, loading map information from a TNT.map file -*-
 */

#include "TMapper.h"

TMapper::TMapper(const char* mapfile="./the.map")
{
  this->InitMap();
  this->LoadMap(mapfile);
}

TMapper::~TMapper()
{
  delete fmap;
}

const void TMapper::InitMap()
{
  fmap = new map<int, string>();
  fidxmap = new map<int, int>();
  ffromidxmap = new map<int, string>();
}

const void TMapper::LoadMap(const char* mapfile)
{
  ifstream fdaqmap(mapfile);
  if (fdaqmap)
    {
      char linebuff[4096];
      int chan;
      char buff[200];
      while (fdaqmap.good())
	{
	  fdaqmap.getline(linebuff, 4096);
	  if (sscanf(linebuff, "%d %s", &chan, buff)==2)
	  if (chan>=0 )
	    {
	      fmap->insert( {chan, string(buff)});
	    }
	}
  fdaqmap.close();
  //cout << "# [MAPPER] Made primary map"<<endl;
    }
    int idx=0;
   for (auto ch = fmap->begin(); ch !=fmap->end(); ch++)
    {
      //cout << "# channel " << ch->second << " is at index " << idx <<endl;
      fidxmap->insert( {ch->first, idx});
      ffromidxmap->insert({idx, ch->second});
      idx++;
    } 
}

const int TMapper::KnowThisChannel(const int chan)
{
    if (fmap->count(chan)==1)
        return 1;
    return 0;
}

const int TMapper::KnowThisIndex(const int idx)
{
    if (ffromidxmap->count(idx)==1)
        return 1;
    return 0;
}

const int TMapper::GetChannelIndex(const int chan)
{
  return (const int) fidxmap->at(chan) ;
}

const char* TMapper::GetChannelName(const int channel)
{
  return ((string) fmap->at(channel)).c_str();
}

const char* TMapper::GetChannelNameFromIndex(const int index)
{
  return ((string) ffromidxmap->at(index)).c_str();
}

const void TMapper::DumpMap()
{
  cout << "# [MAPPER] dump "<<endl;
  cout << "#          "<< fmap->size() << " channels" << endl;
  cout << "# idx \t chan \t name " << endl;
  int idx=0;
  for (auto ch = fmap->begin(); ch !=fmap->end(); ch++)
    {
      cout << "  " << idx << " \t " ;
      cout << ch->first << " \t ";
      cout << ch->second << " " ;
      cout << std::endl;
      idx++;
    }

}

