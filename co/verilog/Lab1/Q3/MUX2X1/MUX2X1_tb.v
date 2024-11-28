`include "MUX2X1.v"

module tb_mux_2x1;

    reg A, B, Sel;
    wire Y;

    // Instantiate the 2x1 MUX
    mux_2x1 uut (
        .A(A),
        .B(B),
        .Sel(Sel),
        .Y(Y)
    );

    initial begin
        $dumpfile("mux_2x1_tb.vcd");  // VCD file for waveform
        $dumpvars(0, tb_mux_2x1);

        $display("2x1 MUX Truth Table:");
        $display("A B Sel | Y");
        $display("----------------");
        for (integer i = 0; i < 8; i++) begin
            {A, B, Sel} = i; // Generate all combinations
            #1;              // Wait for simulation step
            $display("%b %b   %b  | %b", A, B, Sel, Y);
        end

        $finish;
    end
endmodule
