#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <array>
#include <sstream>

struct operation
{
<<<<<<< HEAD
    enum op_type {ADD, SUB, MULT, DIV};
    
    string name;
    op_type type;
    int width;
    string in_edge;
    string out_edge;
};

struct edge
{
    enum edge_type {INPUT, OUTPUT, REG};
    
    char edge_id[MAXIDLEN];
    edge_type type;
    int edge_width;
};

struct fu_resource
{
    char resource_type[MAXIDLEN];  /* resource_type = op_type of the bound op*/
    struct fu_instance instance_list[MAXINSTANCES];
    int count; /* number of operations of this type */
    int max_count; /* max no. of resources needed
		    = max no. of parallel opns of this type in the schedule.
		    */
    int tstep;  //time step
=======
  string type;
  string op1;
  string op2;
  string out;
  int tstep;
>>>>>>> master
};

struct register
{
    string name;
    int t_1;//first access
    int t_2;//last access
};

struct resource
{
  string type;
  vector<int> clique;
};

struct mux
{
    int num_inputs;
    int resource_id;
    string resource_bind;
};


int** func_compat;
int** reg_compat;

std::vector<string> input;
std::vector<string> output;
vector<register> registers;
vector<operation> op;

int in_bit;
int out_bit;
int op_bit;
int reg_bit;

void read_aif(){
<<<<<<< HEAD
  std::string file, line;
=======
  string file;
  string line;
>>>>>>> master

  cout<<"Enter the input file name"<<endl;
  cin>>file;

  ifstream in_file;

  in_file.open(file);

  std::istringstream iss;

  if(!in_file)
  {
    cout<< "Input file doesn't exist";
    exit(1);
  }
<<<<<<< HEAD
  
  getline(file, line); //get inputs
  iss.str(line);
  iss >> discard;
=======

  if(in_file.is_open())//if the file is open run the loops to add the functions in to the vectors
  {
    in_file>line;
    for(int i=0;line != "outputs";i++)
      {
        input.push_back(line);
        in_file>>line;
        if(i=0)
        {
          in_bit = atoi(line<<c_str);
        }
        in_file>>line;
      }


      in_file>>line;
      for(int i=0;line != "regs";i++)
        {
          output.push_back(line);
          in_file>>line;
          if(i=0)
          {
            out_bit = atoi(line<<c_str);
          }
          in_file>>line;
        }

        in>>line;
        for(i=0;line != "op1";i++)
          {
            registers.push_back(reg());
            registers[i].name =line;
            registers[i].t_1=0;
            registers[i].t_2=0;
            in_file>>line;
            if(i=0)
            {
              reg_bit = atoi(line<<c_str);
            }
            in_file>>line;
          }

          in>>line;
          for(i=0;line != "end";i++)
            {
              op.push_back(operation());
              in_file>>line;
              op[i].op_type = line;
              in_file>>line;
              if(i=0)
              {
                op_bit= atoi(line.c_str);
              }
              in_file>>line;
              op[i].op1=line;
              in_file>>line;
              op[i].op2=line;

              in_file>>line;
              op[i].out=line;
              op[i].tstep =0;
              in_file>>line;
            }
}
>>>>>>> master
}
