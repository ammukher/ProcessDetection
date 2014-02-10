#ifndef SPLITTER_H
#define SPLITTER_H

#include <iostream>
#include <vector>
#include <string>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <itkFileTools.h>

using namespace std;

class Splitter {
private:
  unsigned int tile_size, overlap;
  string filename;
  string exe_string;
  vector<string> tileList;
  itk::Size<2> totSize;
  vector< itk::Size<2> > tileSize;
  string parentDirectory;
  typedef itk::RGBPixel<unsigned short> RGBPixelType;
  typedef itk::Image<RGBPixelType,2> RGBImageType;


public: 
  Splitter(string& f) { filename=f; };
  void SetOverlap(int o) { overlap=o;}
  void SetTileSize( int s) { tile_size=s; };
  void Operate(string& );
  void Complete();
};

void Splitter::Operate(string& op) {
  
  itk::ImageFileReader<RGBImageType>::Pointer reader = 
    itk::ImageFileReader<RGBImageType>::New();
  reader->SetFileName(filename);
  try {
    reader->Update();
  }

  catch (itk::ExceptionObject& ex) {
    cout << ex.GetDescription() << endl;
    return;
  }

  itk::FileTools tools;
  size_t n = filename.find_last_of(".");
  if (n != string::npos) {
    parentDirectory = filename.substr(0,n);  
  }
  else {
    parentDirectory.assign("SPLITTER_DIR");
  }
  
  tools.CreateDirectoryA(parentDirectory.c_str());
  totSize = reader->GetImageIO()->Get

}

void Splitter::Complete() {

}


#endif