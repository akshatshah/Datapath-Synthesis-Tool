void  LIST_L (vector<struct operation> G, int a, int b, int c, int d){
    int size = G.size();
    // l is timestep
    int l = 1;
    do {
        for(int op = 0; op < G.size() - 1; op++)
        {
            int operationMULT = 1;
            int operationADD = 1;
            int operationSUB = 1;
            int operationDIV = 1;
            
            if(list[op].v == true){
                op++;
            }
            else if(G[op].type == "MULT"){
                if (operationMUX <= a)
                    list[op].t = l;
                    list[op].v = true;
                    operationMULT++;
            }
            else if(G[op].type == "ADD"){
                if (operationMUX <= b)
                    list[op].t = l;
                    list[op].v = true;
                    operationMUX++;
            }
             else if(G[op].type == "SUB"){
                if (operationMUX <= c)
                    list[op].t = l;
                    list[op].v = true;
                    operationMUX++;
            }
            else if(G[op].type == "DIV"){
                if (operationMUX <= d)
                    list[op].t = l;
                    list[op].v = true;
                    operationMUX++;    
            }
            }else 
                break;
            }
        }
        // Increment time step
        l += 1;

    } while ( G[size].bool == false); // While an operation is unscheduled

}