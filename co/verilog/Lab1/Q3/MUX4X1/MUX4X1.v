module mux_4x1 (
    input A,          // Input 1
    input B,          // Input 2
    input C,          // Input 3
    input D,          // Input 4
    input [1:0] Sel,  // 2-bit Select line
    output reg Y      // Output
);

/*
    // Assign output based on Sel
    assign Y = (Sel == 2'b00) ? A :
               (Sel == 2'b01) ? B :
               (Sel == 2'b10) ? C :
                                D;
*/
    always @(*) begin
        if (Sel == 2'b00)
            Y = A;    // Select A when Sel is 00
        else if (Sel == 2'b01)
            Y = B;    // Select B when Sel is 01
        else if (Sel == 2'b10)
            Y = C;    // Select C when Sel is 10
        else
            Y = D;    // Select D when Sel is 11
    end
endmodule
