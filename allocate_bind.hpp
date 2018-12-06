#ifndef ALLOCATE_BIND
#define ALLOCATE_BIND


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
        if((op[i].type()==op[j].type())&&(op[i].tstep()!=op[j].tstep()
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

      for(i=0;i<MAXCLIQUES;i++)
      {
        if(clique_set[i].size==unknown)
          break;
        printf(" Clique #%d (size = %d) = { ",i, clique_set[i].size);

        for(j=0; j<MAXCLIQUES; j++)
      	{
      	    if(clique_set[i].members[j] != UNKNOWN)
      		printf(" %d ", clique_set[i].members[j]);
      	    else
      		break;
      	}
      	printf (" }\n");
      }
}

void allocate_bind_reg(){

for(i=0;i<registers.size();i++)
{
  op[i].tstep=;
  registers.back().t_1=0;
  int m = op.size();
  for(j=0;j<m;j++)
  {
    if(op[m].op1==input[i]||op[m].op2==input[i])
    registers.back().t_2=op[m].tstep;
  }
}

for(i=0;i<output.size();i++)
{
  registers.push_back(reg());
  registers.back().name()=op[m].output;
  registers.back().t_1=op[m].tstep;
  if(op[m])

  for(j=0;j<m;j++)
  {

  }

}

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
        if((reg[i].first()>=reg[j].last())||(reg[i].last()<=reg[j].first())
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

      for(i=0;i<MAXCLIQUES;i++)
      {
        if(clique_set[i].size==unknown)
          break;
        printf(" Clique #%d (size = %d) = { ",i, clique_set[i].size);

        for(j=0; j<MAXCLIQUES; j++)
      	{
      	    if(clique_set[i].members[j] != UNKNOWN)
      		printf(" %d ", clique_set[i].members[j]);
      	    else
      		break;
      	}
      	printf (" }\n");
      }
}
}

#endif
