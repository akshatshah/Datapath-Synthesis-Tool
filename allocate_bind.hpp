

struct fu_resource
{
    char resource_type[MAXIDLEN];  /* resource_type = op_type of the bound op*/
    struct fu_instance instance_list[MAXINSTANCES];
    int count; /* number of operations of this type */
    int max_count; /* max no. of resources needed
		    = max no. of parallel opns of this type in the schedule.
		    */
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

void allocate(){
  
}
