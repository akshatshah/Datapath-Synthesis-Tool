#include<iostream>
#include<fstream>
#include<string>
#include<vector>

struct operation
{

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
    int first;//first access
    int last;//last access
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

vector<operation> op;

int** func_compat;
int** reg_compat;

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
