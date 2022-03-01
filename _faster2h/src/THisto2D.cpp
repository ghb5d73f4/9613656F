/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- author: G. Henning -*-
 -*- created: Mon Jan 27 11:16:44 CET 2020 -*-
 -*- copyright: GH/IPHC 2020 -*-
 -*- file:  -*-
 -*- purpose: -*-
 **/


#include "THisto2D.h"

THisto2D::THisto2D(const int nbinsx, const float xmin, const float xmax,
		   const int nbinsy, const float ymin, const float ymax  )
{
    fnbinsx = nbinsx;
    fxmin = xmin;
    fxmax = xmax;
    fbinwidthx = (fxmax-fxmin)/fnbinsx ;
    fnbinsy = nbinsy;
    fymin = ymin;
    fymax = ymax;
    fbinwidthy = (fymax-fymin)/fnbinsy ;
    foutofrange = 0 ;

    
    bins = (unsigned short int *) malloc(fnbinsx * fnbinsy * sizeof(unsigned short int));
    //cerr << "# [THISTO2D] allocated bin array" << endl;
    for (int i=0; i<fnbinsx; i++)
      for (int j=0; j<fnbinsy; j++)
      {
        bins[i+j*fnbinsx]=0;
      }
    //cerr << "# [THISTO2D] initiated bins to 0" << endl;
}

THisto2D::~THisto2D()
{
    free(bins);
}

const void THisto2D::Fill(const float x, const float y, const int w)
{
    // find the bin :
  //int((x-self.xmin)/self.xbinwidth)+self.xnbins*int((y-self.ymin)/self.ybinwidth)
  int thebin = (int) floor(((x - fxmin)/fbinwidthx) +
    fnbinsx*  floor((y - fymin)/fbinwidthy)) ;
    //cerr << "# [THISTO2D] (" << x <<", " << y << ") -> [" << (int) (x - fxmin)/fbinwidthx << ", " << (int) (y - fymin)/fbinwidthy << "]"<<endl;
    //cerr << "#                                      ->["<< thebin << "]" <<endl;
    if ((thebin<fnbinsx*fnbinsy) && (thebin>=0))
        bins[thebin]+=w;
    else
        foutofrange+=w;
}

const void THisto2D::SaveAs(const char* filepath, 
			    const unsigned int threshold)
{
   std::ofstream hout (filepath, std::ofstream::out);

   if (hout.good())
   {
       hout << "# xnbins = "<< fnbinsx << " " << endl;
       hout << "# ynbins = "<< fnbinsy << " " << endl;
       hout << "# xmin = "<<fxmin << " " << endl;
       hout << "# xmax = "<<fxmax << " " << endl;
       hout << "# ymin = "<<fymin << " " << endl;
       hout << "# ymax = "<<fymax << " " << endl;

       for (int i=0; i<fnbinsx; i++)
	    for (int j=0; j<fnbinsy; j++)
	   {
	     int thebin = i+j*fnbinsx;
	     if ((bins[thebin]>threshold) )
	       {
		 hout << i << " " << j << " " ;
		 hout << bins[thebin] << " " ;
		 hout << endl;
	       }
	   }
       hout << "# out of range = "<<foutofrange << " " << endl;   
   }

   hout.close();

}


const void THisto2D::Dump(const unsigned int threshold)
{
  this->SaveAs("/dev/stdout", threshold);
}
