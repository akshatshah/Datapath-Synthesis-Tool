#ifndef ALLOCATE_BIND
#define ALLOCATE_BIND



int** func_compat;
int** reg_compat;

vector<operation> op;

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

void allocate_bind_fu(){
  int n= op.size();
  func_compat = new int*[n];

  for(int i=0; i<n; i++)
  {
    func_compat[i]= new int[n];
  }

  for(i=0; i<n; i++){
      for(j=0;j<n;j++){
        if(i==j)
        {
          func_compat[i][j]==1;
          func_compat[j][i]==1;
        }
        if((op[i][j].type()==op[j][i].type())&&(op[i][j].tstep()!=op[j][i].tstep()
        {
          func_compat[i][j]==1;
          func_compat[i][j]==1;
        }
        else{
          func_compat[i][j]==0;
          func_compat[j][i]==0;
        }
      }
      clique_partition(func_compat,n);
}

void allocate_bind_reg(){
  int edge= op.size();
  reg_compat = new int*[n];

  for(int i =0; i<n; i++)
  {
    reg_compat[i]= new int[n];
  }


  for(i=0; i<n; i++){
      for(j=0;j<n;j++){
        if(i==j)
        {
          reg_compat[i][j]==1;
          reg_compat[j][i]==1;
        }
        if((op[i][j].type()==op[j][i].type())&&(op[i][j].tstep()!=op[j][i].tstep()
        {
          reg_compat[i][j]==1;
          reg_compat[i][j]==1;
        }
        else{
          reg_compat[i][j]==0;
          reg_compat[j][i]==0;
        }
      }

      clique_partition(reg_compat,n);
}
}

#endif
