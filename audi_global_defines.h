/* Global Definitions and Variables */

#define MAXIDLEN 32
#define MAXNUMOPS 400
#define MAXNUMEDGES 800         /* Number of edges in CDFG  */
#define MAXRESOURCES 32         /* Number of resource types */
#define MAXINSTANCES 100        /* Max instances of a particular type say adder */
#define MAXTIME 100
#define MAXOPSOURCES 32         /* Number of sources on a op */  
#define MAXMUXSOURCES 100        /* Number of inputs to a mux; Number of drivers to a bus */
#define MAXNUMDESTNS 10         /* Number of sinks to a fu_resource/register/mux/bus */   
#define MAXCLIQUES  MAXNUMEDGES /* Number of cliques */
#define MAXBUSES    1           /* Number of buses */
#define MAXSTACKDEPTH  32       /* Used to keep track of nesting level */
#define MAXSTATEEDGES  32       /* Maximum number of outgoing edges out of a state */
#define MAXNUMLITERALS 32       /* the number of literals in the boolean condition on any state
				   transition edge */ 
#define MAXSTATESIZE   500      /* Maximum number of states */
#define MAXNUMMEMORIES 10       /* number of memory elements */
#define MAXCONTROLBITS 2 * MAXNUMEDGES  /* max number of control lines */

#define UNKNOWN -12345
#define UNDEFINED UNKNOWN
#define NOT_FIXED UNKNOWN
#define EMPTY UNKNOWN

#define OFF 100
#define ON 101

#define OPTYPE      299
#define INPUT_TYPE  300
#define OUTPUT_TYPE 301
#define REG_TYPE    302
#define FUNC        303
#define REGISTER    304
#define MUX         305
#define EDGE        306
#define OPERATION   307
#define BUS         308
#define TRUE        309
#define FALSE       310

#define ADDER       311
#define MULTIPLIER  312
#define SUBTRACTOR  313
#define DIVIDER     314
#define COMPARATOR  315
#define ALU         316

#define ASAP        317
#define ALAP        318

#define SELF         319
#define PREDECESSORS 320
#define SUCCESSORS  321
#define PRED_SUCC   322
#define SCHEDULED   323
#define HYBRID      324

#define DATAPATH    325
#define CONTROLLER  326
#define DESIGN      327

#define FDS         328
#define FDLS        329
#define POWER_FDS   330
#define SAM         331

#define CONSTANT_TYPE 332
#define INTVAL_TYPE 333
#define STRING_TYPE 334
#define WIRE        335

#define EQ          336
#define LT          337
#define GT          338

#define AND         339
#define OR          340
#define NAND        341
#define NOR         342
#define XOR         343
#define XNOR        344
#define NOT         345
#define CONCAT      346

#define UNCONDITIONAL 347

#define CONTROL_TYPE 348
#define DATA_TYPE    349

#define RAM_MEMORY   350
#define ROM_MEMORY   351    

#define RANDOM   352    
#define LE  353    
#define GE  354    
#define NE  355    

#define MAXVERTEX 3*MAXNUMEDGES
#define LARGEINTVAL 10000000000

struct operation 
{
    char op_id[MAXIDLEN];
    int asap_tstep;
    int alap_tstep;
    int tstep; /* scheduled in this timestep */
    int asap_tentative_tstep; /* captures the effect on the pred_succ 
				tsteps when an op is temporarily 
				scheduled in a tstep */ 
    int alap_tentative_tstep; /* captures the effect on the pred_succ 
				tsteps when an op is temporarily scheduled 
				in a tstep */	 	
    int tentative_tstep; /* if tentative_asap_tstep = tentative_alap_tstep 
			   for an op, the tentative_tstep is fixed to 
			   this value */	
    int critical_flag; /* to specifically mark the critical ops */
    int tentative_flag; /* to mark which ops are tentatively_scheduled 
			  to some tstep during the evaluation 
			  of a combination */	
    int soon, late, mu, k;
    char op_type[MAXIDLEN];
    int op_width;
    int k_type; /* defines the k-type for each operation */
    int deferred_flag; /* used in FDLS to check for op-deferral */ 

    char left_input_id[MAXIDLEN];
    char right_input_id[MAXIDLEN];
    char output_id[MAXIDLEN];

    int func_type;  /* one of the following types: 
		       ADDER, SUBTRACTOR, MULTIPLIER, DIVIDER, ALU */
    int tstep_count; /*to check for mobility among a valid combination*/

    float sam_force[MAXTIME][MAXINSTANCES];
    int conn_compat;		
    int input1_edge_index; /*indexes into edge_list[]*/
    int input2_edge_index;
    int output_edge_index;

    int predecessors[MAXNUMOPS];
    int successors[MAXNUMOPS];
    float time[MAXTIME];/*for type-distribution of an opn in a time-step*/
    float total_force[MAXTIME]; /*computes self + ps_force*/
    float total_power[MAXTIME]; /*computes self + ps_power*/
    int bound_to_fu_resource;
    int bound_to_fu_instance;

    int scope; /* To handle conditionals */ 

    /* To handle sub-indexing */
    int left_input_upper_index, left_input_lower_index;
    int right_input_upper_index, right_input_lower_index;
    int output_upper_index, output_lower_index;
};

struct edge
{
    char edge_id[MAXIDLEN];
    int edge_type; /* either INPUT_TYPE, OUTPUT_TYPE, REG_TYPE, CONSTANT_TYPE
		      or UNKNOWN */
    int edge_width; 
    int vector_index; /*to index the vector matrix*/
    int vector_flag; /*TRUE if vectors for this edge 
		       are already in the matrix*/ 	
    int input_to_ops_list[MAXNUMOPS];  
    int output_of_the_op;
    int T_start;
    int T_end;
    int bound_to_register;
    int const_value;   /* valid value if edge_type is CONSTANT_TYPE; 
			  otherwise UNKNOWN */ 
    int is_a_flag;     /* TRUE if this edge is a flag to the controller */
    int flag_index;
};

struct src_des
{
    int type;  /* valid types ={FUNC, REGISTER, MUX, BUS, EDGE, OPERATION} */
               /* depending on the type one of the following has a value */
    int fu_resource_id;
    int fu_instance_id;     
    int register_id;
    int mux_id;
    int edge_index;
    char edge_id;
    int op_index;
};

struct fu_instance
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

struct fu_resource
{
    char resource_type[MAXIDLEN];  /* resource_type = op_type of the bound op*/
    struct fu_instance instance_list[MAXINSTANCES];
    int count; /* number of operations of this type */
    int max_count; /* max no. of resources needed 
		    = max no. of parallel opns of this type in the schedule.
		    */
};

struct r_egister
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

struct mux
{
    int num_inputs;
    int width;
    int cbus_base_index;
    struct src_des sources[MAXMUXSOURCES];  
    struct src_des destination[MAXNUMDESTNS];
};

struct bus
{
    int num_inputs;
    struct src_des sources[MAXMUXSOURCES];  
    struct src_des destination[MAXNUMDESTNS];
};

struct clique
{
    int members[MAXNUMEDGES];
    int size;
};

struct op_type_and_width
{
    int func_type; /* ADD, MULT, SUB, DIV, ALU,*/
    int width;
};

struct graph_vertex
{
    char name[MAXIDLEN];
    int id;
} graph_vertex;

struct literal
{
    int edge_index;
    int form; /* TRUE or FALSE */
}literal;


struct state_edge
{
    int to_state;
    int from_state;
    struct literal boolean_literals[MAXNUMLITERALS]; 
       /* condition is 'and' of the literals which 
	  are in true or complement form of the	flags */
} state_edge;

struct state
{
    int timestep;
    int scope;
    struct state_edge transition[MAXSTATEEDGES];
    int type; /* CONTROL_TYPE, DATA_TYPE */
} state;

struct memory
{
    int type; /* RAM or ROM */
    char mem_id[MAXIDLEN];
    int depth;  /* number of words */
    int word_size;
    struct src_des data;
    struct src_des addr;
    int wr_cbus_index;
    int rd_cbus_index;
} memory;

/* global lists */

struct operation operation_list[MAXNUMOPS]; 
struct edge edge_list[MAXNUMEDGES];
struct fu_resource fu_resource_list[MAXRESOURCES];
struct r_egister register_list[MAXNUMEDGES];
struct memory mem_list[MAXNUMMEMORIES]; /* 7/10/03, Kat */
struct mux mux_list[MAXNUMEDGES];
struct bus bus_list[MAXBUSES];
struct clique clique_set[MAXCLIQUES];

int** compat;

/* Data for header information */

char input_filename[MAXIDLEN];
char design_name[MAXIDLEN];

/* data structures for clique partitioning -- leakage power */
int* birth;
int* death;

/* the vector_array for storing the vector_files */
int vector[1000][200];	
int stream_len;

int i_mode;

/* control */
struct state* state_table;
struct literal scope_transition_table[MAXSTATESIZE][MAXSTATESIZE][MAXNUMLITERALS];
char output_function[MAXSTATESIZE][MAXCONTROLBITS];




