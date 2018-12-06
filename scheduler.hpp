
void  LIST_L (vector<struct operation> G, int a)
{

      int l = 0;
      int x =0;

      vector<operation>scheduled;
      while(x<G.size()){

        int operationMULT = 0;
        int operationADD = 0;
        int operationSUB = 0;
        int operationDIV = 0;

        bool flag = FALSE;

        for(int op = 0; op < G.size(); op++)
        {
          if(G[op].scheduled!=TRUE)
          {
            for(int i=0;i<G.size();i++)
            {
                  if(G[i].out==G[op].op1 || G[i].out==G[op].op2)
                  {
                    if(G[i].tstep==l)
                    {
                      if(G[i].scheduled==TRUE)
                      {
                        flag = TRUE;
                      }
                    }
                }
              }

              if(flag==FALSE)
              {
                    if(G[op].type == "MULT")
                    {
                        if (operationMULT < a)
                            G[op].tstep = l;
                            G[op].scheduled = true;
                            operationMULT++;
                    }
                    else if(G[op].type == "ADD")
                    {
                        if (operationADD < a)
                        {
                            G[op].tstep = l;
                            G[op].scheduled = true;
                            operationADD++;
                        }
                    }
                     else if(G[op].type == "SUB")
                     {
                        if (operationSUB < a)
                        {
                            G[op].tstep = l;
                            G[op].scheduled = true;
                            operationSUB++;
                         }
                    }
                    else if(G[op].type == "DIV")
                    {
                        if (operationDIV < a)
                        {
                            G[op].tstep = l;
                            G[op].scheduled = true;
                            operationDIV++;
                          }
                    }
                    else
                        break;
                    }
                  }
                  }
                }

              }

          }
        }
        }
        x++;// Increment time step
        l++;

      }
}
