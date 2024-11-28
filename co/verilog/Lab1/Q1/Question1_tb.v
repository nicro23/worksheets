/*
Implementation of test bench of 
simple combinational circuit
*/
`include "Question1.v"

module Qustion1_tb;
    reg A, B, C, D, E; // Inputs
    wire Y; // Output
    
   // ComCir1 Comb1(A, B, C, D, E, Y);
    //uut -> unit under test
    ComCir1 uut (
    .A(A), 
    .B(B), 
    .C(C), 
    .D(D), 
    .E(E), 
    .Y(Y)
);


// Test the circuit
    initial begin

        $dumpfile("Question1_tb.vcd");   // VCD stands for Value Change Dump, which is a file format that stores the values of signals 
        $dumpvars(0, Qustion1_tb); // Dump all signals in tb_combinational_circuit and The 0 means dump everything

        // Monitor the inputs and output
        $monitor("Time=%0t | A=%b, B=%b, C=%b, D=%b, E=%b | Y=%b", $time, A, B, C, D, E, Y);

        // Test all combinations of inputs
        for (integer i = 0; i < 32; i++) begin
            {A, B, C, D, E} = i; // Assign input combinations
            #1;                // Wait for 1 time units
        end

        $finish; // End the simulation
    end
endmodule