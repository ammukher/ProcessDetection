#include <iostream>
#include <string>
#include <sstream>

#include "splitter.h"

using namespace std;

int main( int argc, char * argv[]) {
  if (argc < 3) {
    cout << "Usage : -tag value " << endl;
    cout << "\t -s image_file " << endl;
    cout << "\t -r executable to run with parameters " << endl;
    cout << "\t -n tile_size " << endl;
    cout << "\t -o overlap " << endl;;
    return EXIT_FAILURE;
  }

  string filename, exe_param;
  unsigned int tile_size = 0, overlap = 0;
  int i = 1;
  while(i < (argc-1)) {
    string tag, value;
    if (argv[i][0] == '-') {
      tag.assign(argv[i]+1);
      i++;
    }
    if (i<argc) {
      value.assign(argv[i]);
      i++;
    }
    cout << "Tag: " << tag << " Value: " << value << endl;
    if (tag.compare("s")==0) {
      filename = value;
    }
    else if (tag.compare("r")==0) {
      exe_param = value;
    }
    else if (tag.compare("n")==0) {
      istringstream(value) >> tile_size;
    }
    else if (tag.compare("o")==0) {
      istringstream(value) >> overlap;
    }
    else {
      cout << "Cannot understand file " << endl;
      return EXIT_FAILURE;
    }

  }


  Splitter split(filename);
  if (tile_size > 0)  {
    split.SetTileSize(tile_size);
  }
  if (overlap == 0) {
    split.SetOverlap(overlap);
  }
  cout << "Starting splitting files" << endl;
  split.Operate(exe_param);
  cout << "Completing the split operation" << endl;
  split.Complete();
  return EXIT_SUCCESS;
}