`include "MUX4X1.v"

module tb_mux_4x1;

    reg A, B, C, D;
    reg [1:0] Sel;
    wire Y;

    // Instantiate the 4x1 MUX
    mux_4x1 uut (
        .A(A),
        .B(B),
        .C(C),
        .D(D),
        .Sel(Sel),
        .Y(Y)
    );

    initial begin
        $dumpfile("mux_4x1_tb.vcd");  // VCD file for waveform
        $dumpvars(0, tb_mux_4x1);

        $display("4x1 MUX Truth Table:");
        $display("A B C D Sel | Y");
        $display("-----------------");
        for (integer i = 0; i < 64; i = i + 1) begin
            {A, B, C, D, Sel} = i; // Generate all combinations
            #1;                   // Wait for simulation step
            $display("%b %b %b %b %b  | %b", A, B, C, D, Sel, Y);
        end

        $finish;
    end
endmodule
