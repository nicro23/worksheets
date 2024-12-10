`include "ALU.v"
`timescale 1ps/1ps

module MIPS_ALU_tb;

    reg [31:0] A, B;        // Test inputs
    reg [3:0] ALUControl;   // Control signal
    wire [31:0] ALUResult;  // Result from ALU
    wire Zero;              // Zero flag

    // Instantiate the ALU module
    MIPS_ALU uut (
        .A(A),
        .B(B),
        .ALUControl(ALUControl),
        .ALUResult(ALUResult),
        .Zero(Zero)
    );

    initial begin

        $dumpfile("ALU_tb.vcd");   // VCD stands for Value Change Dump, which is a file format that stores the values of signals 
        $dumpvars(0, MIPS_ALU_tb); // Dump all signals in MIPS_ALU_tb and The 0 means dump everything

        // Test AND
        A = 32'hF0F0F0F0; B = 32'h0F0F0F0F; ALUControl = 4'b0000; #1;
        $display("AND: %h & %h = %h, Zero = %b", A, B, ALUResult, Zero);

        // Test OR
        A = 32'hF0F0F0F0; B = 32'h0F0F0F0F; ALUControl = 4'b0001; #1;
        $display("OR: %h | %h = %h, Zero = %b", A, B, ALUResult, Zero);

        // Test ADD
        A = 32'd10; B = 32'd20; ALUControl = 4'b0010; #1;
        $display("ADD: %d + %d = %d, Zero = %b", A, B, ALUResult, Zero);

        // Test SUB
        A = 32'd20; B = 32'd20; ALUControl = 4'b0110; #1;
        $display("SUB: %d - %d = %d, Zero = %b", A, B, ALUResult, Zero);

        // Test SLT
        A = 32'd15; B = 32'd20; ALUControl = 4'b0111; #1;
        $display("SLT: %d < %d = %d, Zero = %b", A, B, ALUResult, Zero);

        // Test NOR
        A = 32'hF0F0F0F0; B = 32'h0F0F0F0F; ALUControl = 4'b1100; #1;
        $display("NOR: ~( %h | %h ) = %h, Zero = %b", A, B, ALUResult, Zero);

        $finish;
    end

endmodule
