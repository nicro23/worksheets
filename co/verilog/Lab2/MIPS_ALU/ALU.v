module MIPS_ALU (
    input [31:0] A,        // First operand (32-bit)
    input [31:0] B,        // Second operand (32-bit)
    input [3:0] ALUControl, // Control signal to select operation
    output reg [31:0] ALUResult, // Result of the operation
    output Zero          // Zero flag
);

    // Compute Zero flag (True if ALUResult is 0)
    assign Zero = (ALUResult == 32'b0);

    always @(*) begin
        case (ALUControl)
            4'b0000: ALUResult = A & B;         // AND
            4'b0001: ALUResult = A | B;         // OR
            4'b0010: ALUResult = A + B;         // ADD
            4'b0110: ALUResult = A - B;         // SUB
            4'b0111: ALUResult = (A < B) ? 32'b1 : 32'b0; // SLT (Set On Less Than)
            4'b1100: ALUResult = ~(A | B);      // NOR
            default: ALUResult = 32'b0;         // Default to 0
        endcase
    end

endmodule
