#include <fstream>
#include <string>
using namespace std;
char* readfile (char *filename)
{  // open input file
    ifstream infile;
  try {    infile.open(filename);
    string msg1("Unable to open file ");
    if (!infile.is_open())
    {      // throw "Unable to open file " + filename;
        throw (msg1 =+ filename);
    }
    // get length of file
    infile.seekg (0, ios::end);
    int length = infile.tellg();
    infile.seekg (0, ios::beg);
    // allocate memory
    char *buffer = new char [length];
    // read data from file
    infile.read (buffer,length);
    string msg2("Unable to read from file ");
    if (!infile.good())
    {
         // throw "Unable to read from file " + filename;
          throw (msg2 += filename);
    }
     infile.close();
    return buffer;
    }
    catch (...)
    {
    /* bug: insert code to handle this later */
    }
    
    return NULL;
    
}