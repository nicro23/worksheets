module Instruction_Memory (
    input [31:0] Instruction_Address,        // 32-bit inst address to get the instruction from
    output reg [31:0] Instruction // 32-bit instruction got from memory
);

    //  memory to store bytes 
    reg [7:0] mem [0:127];    // 128 bytes    
    initial 
    begin 
        // Initialize all memory locations to 0 
        for (integer k = 0; k < 128; k = k + 1) 
        begin
            mem[k] = 0;   // Clear all memory bytes
        end
        
        // examples
        // 0x20020002: add $t0, $t1, $t2 (in hexadecimal format)
        //
        mem[0] = 1; //  (opcode)
        mem[1] = 2; //  (rt register)
        mem[2] = 3; // (rs register)
        mem[3] = 2; // (immediate value
        
        // 0x20030002: andi $3, $0, 2 (in decimal format)
        mem[4] = 192;  // (opcode )
        mem[5] = 3;    // (rt register)
        mem[6] = 0;    // (rs register)
        mem[7] = 2;    // (immediate value)
        
    end

    // Instruction Fetch Logic 
    always @(*) 
    begin
        // read 4 bytes after each other to form a 32-bit instruction 
        Instruction = {mem[Instruction_Address[31:0]], mem[Instruction_Address[31:0] + 1], mem[Instruction_Address[31:0] + 2], mem[Instruction_Address[31:0] + 3]}; 
    end

endmodule
