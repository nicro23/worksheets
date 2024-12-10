`include "DataMem.v"
`timescale 1ps/1ps

module DataMemory_tb;

    // Testbench signals
    reg [31:0] Address;
    reg [31:0] WriteData;
    reg MemRead;
    reg MemWrite;
    reg ByteEnable;
    reg HalfwordEnable;
    reg WordEnable;
    wire [31:0] ReadData;

    // Instantiate the DataMemory module
    DataMemory uut (
        .Address(Address),
        .WriteData(WriteData),
        .MemRead(MemRead),
        .MemWrite(MemWrite),
        .ByteEnable(ByteEnable),
        .HalfwordEnable(HalfwordEnable),
        .WordEnable(WordEnable),
        .ReadData(ReadData)
    );

    // Test the Data memory
    initial begin
        $dumpfile("DataMem_tb.vcd");   
        $dumpvars(0, DataMemory_tb); 

        // Initialize all inputs
        MemWrite = 0; MemRead = 0; WordEnable = 0; HalfwordEnable = 0; ByteEnable = 0; Address = 32'h0;

        // Test case 1: Read the word (4 bytes) from address 0x0
        MemWrite = 0; MemRead = 1; WordEnable = 1; HalfwordEnable = 0; ByteEnable = 0; Address = 32'h0;
        #1

        // Test case 2: Read the half (2 bytes) from address 0x4
        MemWrite = 0; MemRead = 1; WordEnable = 0; HalfwordEnable = 1; ByteEnable = 0; Address = 32'h4;
        #1

        // Test case 3: Write a halfword (2 bytes) to address 0x6
        MemWrite = 1; MemRead = 0; WordEnable = 0; HalfwordEnable = 1; ByteEnable = 0; Address = 32'h6;
        WriteData = 32'h0000EF12; // Lower 16 bits = 0xEF12
        #1;

        // Test case 4: Read the half (2 bytes) from address 0x6
        MemWrite = 0; MemRead = 1; WordEnable = 0; HalfwordEnable = 1; ByteEnable = 0; Address = 32'h6;
        #1

        // Test case 5: Over-Write byte to address 0x6
        MemWrite = 1; MemRead = 0; WordEnable = 0; HalfwordEnable = 0; ByteEnable = 1; Address = 32'h6;
        WriteData = 32'h00000034; // Lower 8 bits = 0x34
        #1;

        // Test case 6: Read the half (2 bytes) from address 0x6 after the change in test case 5
        MemWrite = 0; MemRead = 1; WordEnable = 0; HalfwordEnable = 1; ByteEnable = 0; Address = 32'h6;
        #1

 
        // Finish the simulation
        $finish;
    end

    // Monitor outputs
    initial begin
        $monitor("Time: %0t | Address: %h | WriteData: %h | ReadData: %h | MemRead: %b | MemWrite: %b | ByteEnable: %b | HalfwordEnable: %b | WordEnable: %b",
                 $time, Address, WriteData, ReadData, MemRead, MemWrite, ByteEnable, HalfwordEnable, WordEnable);
    end

endmodule
