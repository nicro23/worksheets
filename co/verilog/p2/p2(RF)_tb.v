`include "p2(RF).v"
`timescale 1ps/1ps

module RegisterFile_tb;

    // Testbench signals
    reg [31:0] R_Address;
    reg [31:0] W_Address;
    reg read_enable;
    reg write_enable;
    reg [7:0] WriteData;
    wire [7:0] ReadData;

    // Instantiate the RegisterFile module
    RegisterFile uut (R_Address, W_Address, read_enable, write_enable, WriteData, ReadData);

    // Test the register file
    initial begin
        $dumpfile("RF_tb.vcd");   
        $dumpvars(0, RegisterFile_tb); 

        // Test case 1: Reset register file
        write_enable = 0; read_enable = 0; R_Address = 32'h0; W_Address = 32'h0;
        #1;

        // Test case 2: Read all registers while empty
        write_enable = 0; read_enable = 1;  R_Address = 32'h0;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h1;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h2;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h3;
        #1;

        // Test case 3: Write data into all registers
        write_enable = 1; read_enable = 0; R_Address = 32'h0; W_Address = 32'h0; WriteData = 8'h1;
        #1;
        write_enable = 1; read_enable = 0; R_Address = 32'h0; W_Address = 32'h1; WriteData = 8'h2;
        #1;
        write_enable = 1; read_enable = 0; R_Address = 32'h0; W_Address = 32'h2; WriteData = 8'h3;
        #1;
        write_enable = 1; read_enable = 0; R_Address = 32'h0; W_Address = 32'h3; WriteData = 8'h4;
        #1;

        // Test case 4: Read all registers while full
        write_enable = 0; read_enable = 1;  R_Address = 32'h0;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h1;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h2;
        #1;
        write_enable = 0; read_enable = 1;  R_Address = 32'h3;
        #1;
 
        // Finish the simulation
        $finish;
    end

    // Monitor outputs
    initial begin
        $monitor("Time: %0t | R_Address: %h | W_Address: %h | WriteData: %h | ReadData: %h | read_enable: %b | write_enable: %b |",
                 $time, R_Address, W_Address, WriteData, ReadData, read_enable, write_enable);
    end

endmodule
