#include "infdef.h"
#include <iostream>
 
using namespace std;
 
/* compress or decompress */
int main(void)
{
   int ret;
   string request="";
 
   while (true)
   {
	  cout<<"Do you want to compress or decompress a file (to exit 'CTRL+C')? <comp|decomp>"<<endl;
	  cin>>request;
	  if (request=="comp" || request=="decomp")
		break;
   }
 
  string name_file_source = "";
  string name_file_dest = "";
  float size_src=0.0, size_dest=0.0;
 
  /*
   Enter or path to file, for example:
   C:/Users/User/file.txt
   Or
   If you save the file in the bin folder, where
   you will have the *.exe file, you just need write
   name and extension file:
	   file.txt
  */
 
  cout<<"Enter file source name: "<<endl;
  cin>>name_file_source;
  cout<<"Enter file destination name: "<<endl;
  cin>>name_file_dest;
 
  FILE *source=NULL;//original file
  FILE* dest=NULL; //file to compress or decompress
 
 /* do compression if "comp" specified */
   if (request == "comp") {
	  try
	  {
		 source = fopen(name_file_source.c_str(),"r");
		 if(!source)
			throw 0;
	  }
	  catch (int n)
	  {
		 cout << "File does not exist, method return with " << n << endl;
		 return 0;
	  }
  
	  dest = fopen(name_file_dest.c_str(),"wb");//wb because write to binary format
	  ret = def(source, dest ,Z_DEFAULT_COMPRESSION);
	  if (ret != Z_OK)
		 zerr(ret);
	  else
	  {
		/* Calculate size file to see the difference */
		size_src = ftell(source);
		size_dest = ftell(dest);
	
		cout<<"The original file size is: "<<size_src<<endl;
		cout<<"The file size after being compressed is: "<<size_dest<<endl;
	  }
	  return ret;
   }
	
   /* do decompression if "decomp" specified */
   else {
	  try
	  {
		 source = fopen(name_file_source.c_str(),"rb");//rb because read from binary format
		 if(!source)
			throw 0;
	  }
	  catch (int n)
	  {
		 cout << "File does not exist, method return with " << n << endl;
		 return 0;
	  }
  
	  dest = fopen(name_file_dest.c_str(),"w");
	  ret = inf(source, dest);
	  if (ret != Z_OK)
		 zerr(ret);
	  else
	  {
		/* Calculate size file to see the difference */
		size_src = ftell(source);
		size_dest = ftell(dest);
	
		cout<<"The original file size is: "<<size_src<<endl;
		cout<<"The file size after being decompressed is: "<<size_dest<<endl;
	  }
	  return ret;
	}
  return 1;
}
