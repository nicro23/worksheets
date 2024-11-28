module mux_2x1(
    input A,        // Input 1
    input B,        // Input 2
    input Sel,      // Select line
    output reg Y        // Output
    //reg is a data type in Verilog that holds its value until it is explicitly updated.
);
    // Assign output based on Sel
    //assign Y = (Sel) ? B : A; //using ternary operator

    always @(*) begin
        if (Sel == 1'b0)
            Y = A;  // Select A when Sel is 0
        else
            Y = B;  // Select B when Sel is 1
    end
    /*
    always @(*) begin
    end

    note-> Ensures that the block executes every time 
           there's a change in any input signal used in the block.

    */

endmodule
