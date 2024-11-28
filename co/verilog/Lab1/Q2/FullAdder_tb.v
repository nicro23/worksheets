`include "FullAdder.v"

module tb_full_adder;
    reg A, B, Cin;         // Inputs
    wire Sum, Cout;        // Outputs

    // Instantiate the Full Adder
    full_adder uut (
        .A(A),
        .B(B),
        .Cin(Cin),
        .Sum(Sum),
        .Cout(Cout)
    );

    // Testbench logic
    initial begin
        $dumpfile("full_adder_tb.vcd");  // Generate waveform file
        $dumpvars(0, tb_full_adder);    // Dump all signals

        // Display Header
        $display("A B Cin | Sum Cout");
        $display("------------------");

        // Iterate through all input combinations
        for (integer i = 0; i < 8; i = i + 1) begin
            {A, B, Cin} = i;           // Assign combinations of A, B, Cin
            #1;                        // Wait for 1 time unit
            $display("%b %b  %b  |  %b   %b", A, B, Cin, Sum, Cout); // Display results
        end

        $finish;  // End simulation
    end
endmodule
