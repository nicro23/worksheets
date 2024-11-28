/*
Implementation of simple combinational circuit
*/

module ComCir1 (input A, B, C, D, E,output Y);
/*  input A, B, C, D, E;
    output Y;
    wire w1, w2, w3, w4;*/
 /*   
    // Gate instantiations (STRUCTURAL)
    or o1(w1, A, B);        // OR gate o1: w1 = A | B
    not n1(w3, w1);         // NOT gate n1: w3 = ~w1
    and a1(w2, C, D);       // AND gate a1: w2 = C & D
    or o2(w4, w3, w2);      // OR gate o2: w4 = w3 | w2
    and a2(Y, w4, E);       // AND gate a2: Y = w4 & E
*/
/*  (BEHAVIORAL)
    assign w1 = A | B;
    assign w2 = C & D;
    assign w3 = ~w1;
    assign w4 = w3 | w2;
    assign Y = E & w4;*/

    assign Y = ( ( (~(A | B)) | (C & D) ) & E); 
    

endmodule