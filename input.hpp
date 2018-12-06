#include<iostream>
#include<fstream>
#include<string>
#include<vector>

void read_aif(){
  string file;

  cout<<"Enter the input file name"<<endl;
  cin>>file;

  ifstream in_file;

  in_file.open(file);

  if(!in_file)
  {
    cout<< "Input file doesn't exist";
    exit(1);
  }
  while(line!= "outputs")
  {

  }
  while(line!="regs")
  {

  }
  while(line!="op1")
  {

  }

  while(line!="end")
  {

  }
}
