void  LIST_L (vector<struct operation> G, int a){
    int size = G.size();
    // l is timestep
    int l = 1;
    do {
        for(int op = 0; op < G.size() - 1; op++)
        {
            int operationNum = 1;
            if(G[op].bool == true){
                op++

            }else if (operationNum <= a) {
                G[op].t = l
                G.[op].bool = true;
                operationNum++;

            }else
                break;
            }
        }
        // Increment time step
        l += 1;

    } while ( G[size].bool == false); // While an operation is unscheduled

}