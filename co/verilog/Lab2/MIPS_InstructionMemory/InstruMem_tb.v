`include "InstruMem.v"
`timescale 1ps/1ps

module tb_InstructionMemory;

    // Testbench signals
    reg [31:0] Address;         // Address to fetch instruction from
    wire [31:0] Instruction;    // Instruction fetched from memory

    // Instantiate the InstructionMemory module
    InstructionMemory IM (
        .Address(Address),
        .Instruction(Instruction)
    );

    // Test the instruction memory
    initial begin
        $dumpfile("InstruMem_tb.vcd");   
        $dumpvars(0, tb_InstructionMemory); 

        // Display the instruction at each address
        $display("Testing Instruction Memory");

        // Test Case 1: Fetch instruction at address 0x0 (Address 0)
        Address = 32'h00000000;
        #10; // Wait for 10 time units
        $display("Address: %h, Instruction: %h", Address, Instruction);

        // Test Case 2: Fetch instruction at address 0x4 (Address 1)
        Address = 32'h00000004;
        #10; // Wait for 10 time units
        $display("Address: %h, Instruction: %h", Address, Instruction);

        // Test Case 3: Fetch instruction at address 0x8 (Address 2)
        Address = 32'h00000008;
        #10; // Wait for 10 time units
        $display("Address: %h, Instruction: %h", Address, Instruction);

        // Test Case 4: Fetch instruction at address 0xC (Address 3)
        Address = 32'h0000000C;
        #10; // Wait for 10 time units
        $display("Address: %h, Instruction: %h", Address, Instruction);

        // Test Case 5: Fetch instruction at address 0x10 (Address 4)
        Address = 32'h00000010;
        #10; // Wait for 10 time units
        $display("Address: %h, Instruction: %h", Address, Instruction);

        // Finish the simulation
        $finish;
    end

endmodule
