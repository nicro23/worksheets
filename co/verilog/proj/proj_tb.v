`include "proj.v"
`timescale 1ps/1ps

module MIPS_datapath_tb;

    reg clk;
    reg write_enable, write_memory, read_memory, branch;
    reg [1:0] aluop;
    // Instantiate the ALU module
    MIPS_datapath test(clk, write_enable, write_memory, read_memory, branch);

    initial begin

        $dumpfile("datapath.vcd");
        $dumpvars(0, MIPS_datapath_tb);
        //rtype signals
        write_enable = 1; write_memory = 0; read_memory = 0; branch = 0; aluop = 10; clk = 0; #1;
        for(integer i = 0; i < 6; i++)begin
        clk = 1; 
        #1;
        end
        //lw signals
        write_enable = 1; write_memory = 0; read_memory = 1; branch = 0; aluop = 00; clk = 0; #1;
        // for(integer i = 0; i < 6; i++)begin
        // clk; 
        // #1;
        // end
        //beq signals
        write_enable = 0; write_memory = 0; read_memory = 0; branch = 1; aluop = 01; clk = 0; #1;
        // for(integer i = 0; i < 6; i++)begin
        // clk++; 
        // #1;
        // end
        $finish;
    end

endmodule
