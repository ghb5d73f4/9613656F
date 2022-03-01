/**
 -*- coding: utf-8 -*-
 -*- format: c++ -*-
 -*- file: argparse.h -*-
 -*- author: G.Henning -*-
 -*- copyright: GH / IPHC (2013) -*-
 -*- date:  Sept 26 2013 -*-
 -*- purpose: Parse arguments from command line -*-
**/

#ifndef ARGPARSE_H_


/* Prototypes */
const int ParseFlag(const int argc,
		    const char* argv[],
		    const char* flag);

const int ParseInt(const int argc,
		   const char* argv[],
		   const char* arg,
		   const int orelse);

const float ParseFloat(const int argc,
		       const char* argv[],
		       const char* arg,
		       const float orelse);

const char* ParseString(const int argc,
			const char* argv[],
			const char* arg,
			const char* orelse);
#define ARGPARSE_H_
#endif
