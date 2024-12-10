module InstructionMemory (
    input [31:0] Address,        // 32-bit address to fetch the instruction from
    output reg [31:0] Instruction // 32-bit instruction fetched from memory
);

    // Declare memory to store bytes (128 bytes total, 32 addresses with 1 byte each)
    reg [7:0] memory [0:127];    // 128 bytes of memory

    // Initial block to load some test instructions into memory
    initial begin        // Initialize all memory locations to 0 (for simplicity)
        for (integer i = 0; i < 128; i = i + 1) begin
            memory[i] = 8'b0;   // Clear all memory bytes
        end
        
        // Loading some example instructions into memory
        // Each instruction is 4 bytes (32 bits), and instructions will be stored in consecutive bytes
        // Example instructions (just for illustration):
        // 0x20020001: addi $2, $0, 1 (in hexadecimal format)
        memory[0] = 8'h20; // Instruction byte 1
        memory[1] = 8'h02; // Instruction byte 2
        memory[2] = 8'h00; // Instruction byte 3
        memory[3] = 8'h01; // Instruction byte 4
        
        // 0x20030002: addi $3, $0, 2
        memory[4] = 8'h20;
        memory[5] = 8'h03;
        memory[6] = 8'h00;
        memory[7] = 8'h02;
        
        // 0x00000000: nop (no operation)
        memory[8] = 8'h00;
        memory[9] = 8'h00;
        memory[10] = 8'h00;
        memory[11] = 8'h00;
        
        // 0x01034020: add $8, $8, $9
        memory[12] = 8'h01;
        memory[13] = 8'h03;
        memory[14] = 8'h40;
        memory[15] = 8'h20;
        
        // 0x20040004: addi $4, $0, 4
        memory[16] = 8'h20;
        memory[17] = 8'h04;
        memory[18] = 8'h00;
        memory[19] = 8'h04;
    end

    // Instruction Fetch Logic (handle 4-byte word-aligned access)
    always @(*) begin
        // read 4 consecutive bytes to form a 32-bit instruction
        Instruction = {memory[Address[31:0]], memory[Address[31:0] + 1], memory[Address[31:0] + 2], memory[Address[31:0] + 3]}; 
    end

endmodule
