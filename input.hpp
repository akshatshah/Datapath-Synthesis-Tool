#include<iostream>
#include<fstream>
#include<string>
#include<vector>

struct operation
{
  string type;
  string op1;
  string op2;
  string out;
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
};

struct register
{
    int mapped_edges[MAXNUMEDGES]; /* clique members */
    int source_ops[MAXNUMOPS];
    int source_edges[MAXNUMEDGES]; /* field added on 7/5/03 by Kat to handle
				      ASSIGN operations which give rise
				      to multiple registers writing to a register */
    int width;
    int cbus_index;
    struct src_des source;
    struct src_des destination[MAXNUMDESTNS];
    int sleep_ctrl_index;
    int off_steps[MAXTIME];
    int t_1;//first access
    int t_2;//last access
};

struct func_unit
{
    int allocated;   /* flag set to TRUE if this instance is allocated */
    char resource_type[MAXIDLEN];  /* resource_type = op_type of the bound op*/
    int width;
    struct src_des physical_source_input1;
    struct src_des physical_source_input2;
    struct src_des input1_source_edges[MAXOPSOURCES];
    struct src_des input2_source_edges[MAXOPSOURCES];
    struct src_des destination[MAXNUMDESTNS];
    int mapped_ops[MAXNUMOPS];
    /* leakage power */
    int cbus_index;
    int off_steps[MAXTIME];
};

struct mux
{
    int num_inputs;
    int resource_id;
    string resource_bind;
};

struct
int** func_compat;
int** reg_compat;

std::vector<string> input;
std::vector<string> output;
vector<register> registers;
vector<operation> op;
vector<o>;

int in_bit;
int out_bit;
int op_bit;
int reg_bit;

void read_aif(){
  string file;
  string line;

  cout<<"Enter the input file name"<<endl;
  cin>>file;

  ifstream in_file;

  in_file.open(file);

  if(!in_file)
  {
    cout<< "Input file doesn't exist";
    exit(1);
  }

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

              if(i=1)
              {
                in_bit = atoi(line<<c_str);
              }
              in_file>>line;
              op[i].out=line;
              op[i].tstep =0;
              in_file>>line;
            }
}
}
