#ifndef ZIPFILE_H
#define ZIPFILE_H

#include "zipios++/zipios-config.h"

#include <vector>
#if defined (HAVE_STD_IOSTREAM) && defined (USE_STD_IOSTREAM)
#include <iostream>
#include <fstream>
#else
#include <iostream.h>
#include <fstream.h>
#endif

#include "zipios++/fcoll.h"
#include "zipios++/ziphead.h"
#include "zipios++/virtualseeker.h"

namespace zipios {

using std::ifstream ;

/** \anchor zipfile_anchor
    ZipFile is a FileCollection, where the files are stored
 in a .zip file.  */
class ZipFile : public FileCollection {
public:
  static ZipFile openEmbeddedZipFile( const string &name ) ;
  ZipFile() {}
  explicit ZipFile( const string &name, int s_off = 0, int e_off = 0
		    /* , ios::open_mode mode  = ios::in | ios::binary */ ) ;
  virtual ~ZipFile() ;

  virtual void close() ;

  virtual istream *getInputStream( const ConstEntryPointer &entry ) ;
  virtual istream *getInputStream( const string &entry_name, 
				     MatchPath matchpath = MATCH ) ;
private:
  VirtualSeeker _vs ;
  EndOfCentralDirectory  _eocd ;

  bool init( istream &_zipfile ) ;
  bool readCentralDirectory( istream &_zipfile ) ;
  bool readEndOfCentralDirectory( istream &_zipfile ) ;
  bool confirmLocalHeaders( istream &_zipfile ) ;
  void setError( string error_str ) ;
};

}

#endif

/** \file
    Header file that defines ZipFile.
*/

/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000  Thomas S�ndergaard
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/