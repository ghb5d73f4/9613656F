/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- author: G. Henning -*-
 -*- created: Mon Jan 27 11:16:44 CET 2020 -*-
 -*- copyright: GH/IPHC 2020 -*-
 -*- file:  -*-
 -*- purpose: -*-
 **/


#include "THisto.h"

THisto::THisto(const int nbins,
         const float xmin, 
         const float xmax)
{
    fnbins = nbins;
    fxmin = xmin;
    fxmax = xmax;
    foutofrange = 0 ;
    fbinwidth = (fxmax-fxmin)/fnbins ;
    
    bins = (unsigned long int *) malloc(fnbins * sizeof(unsigned long int));

    for (int i=0; i<fnbins; i++)
      {
        bins[i]=0;
      }
}

THisto::~THisto()
{
    free(bins);
}

const void THisto::Fill(const float x, const int w)
{
    // find the bin : 
    int thebin = (int) (x - fxmin)/fbinwidth ;
    if ((thebin<fnbins) && (thebin>=0))
        bins[thebin]+=w;
    else
        foutofrange+=w;
}

const void THisto::SaveAs(const char* filepath, 
                          const unsigned int threshold)
{
   std::ofstream hout (filepath, std::ofstream::out);

   if (hout.good())
   {
       hout << "# nbins = "<< fnbins << " " << endl;
       hout << "# xmin = "<<fxmin << " " << endl;
       hout << "# xmax = "<<fxmax << " " << endl;
       for (int i=0; i<fnbins; i++)
       {
	 if (bins[i]>=threshold)
	   {
	     hout << fxmin+i*fbinwidth << " " ;
	     hout << fbinwidth << " " ;
	     hout << bins[i] << " " ;
	     hout << endl;
	   }
       }
       hout << "# out of range = "<<foutofrange << " " << endl;   
   }

   hout.close();

}


const void THisto::Dump(const int unsigned threshold)
{
    cout << "# nbins = "<< fnbins << " " << endl;
    cout << "# xmin = "<<fxmin << " " << endl;
    cout << "# xmax = "<<fxmax << " " << endl;
    for (int i=0; i<fnbins; i++)
      {
        cout << fxmin+i*fbinwidth << " " ;
        cout << fbinwidth << " " ;
        cout << bins[i] << " " ;
        cout << endl;
      }
    cout << "# out of range = "<<foutofrange << " " << endl;   
}
