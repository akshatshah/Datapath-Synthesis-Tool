#ifndef MUX_GEN
#define MUX_GEN

#include "allocate_bind.h"

void mux_gen()
{
  for(int i=0; i< register_num.size(); i++)
  if (register_num[i].size()>i) {
    mux_vector.push_back(mux());
    mux_vector.back().num_inputs = register_num[i].size();
    mux_vector.back().resource_bind= "REG";
    mux_vector.back().resource_id=i;
  }


  for(int i=0; i< operator_num.size();i++ )
  {
    if (operator_num[i].clique.size()>i) {
      mux_vector.push_back(mux());
      mux_vector.back().num_inputs = operator_num[i].clique.size();
      mux_vector.back().resource_bind= opertor_num[i].clique.type();
      mux_vector.back().resource_id=i;
    }
  }
}
