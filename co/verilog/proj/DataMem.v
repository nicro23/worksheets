module DataMemory (
    input [31:0] Instruction_Address,   // Address for read/write operation
    input [31:0] W_Data,                // Data to write to memory
    output reg [31:0] R_Data,           // Data read from memory
    input Read_M,                       // Read control signal
    input Write_M,                      // Write control signal
    input OneByte,                      // Enable byte read/write
    input HalfWord,                     // Enable halfword read/write
    input OneWord                       // Enable word read/write
);

    // Memory storage: 512 bytes
    reg [7:0] mem [0:511];    


    initial 
    begin
        // Clear memory
        for (integer k = 0; k < 512; k = k + 1) 
            mem[k] = 0;   

        // Example test data :
        mem[0] = 18;   // Byte 0
        mem[1] = 52;   // Byte 1
        mem[2] = 86;   // Byte 2
        mem[3] = 120;  // Byte 3
        mem[4] = 154;  // Byte 4
        mem[5] = 188;  // Byte 5
    end

    // Read/Write Logic
    always @(*) begin
        if (Read_M) begin
            if (OneWord) begin
                // Read 32-bit word (4 bytes)
                R_Data = {mem[Instruction_Address], mem[Instruction_Address+1], mem[Instruction_Address+2], mem[Instruction_Address+3]};
            end else if (HalfWord) begin
                // Read 16-bit halfword (2 bytes)
                R_Data = {16'b0, mem[Instruction_Address], mem[Instruction_Address+1]};
            end else if (OneByte) begin
                // Read 8-bit byte
                R_Data = {24'b0, mem[Instruction_Address]};
            end
        end else if (Write_M) begin
            if (OneWord) begin
                // Write 32-bit word (4 bytes)
                mem[Instruction_Address] = W_Data[31:24];
                mem[Instruction_Address+1] = W_Data[23:16];
                mem[Instruction_Address+2] = W_Data[15:8];
                mem[Instruction_Address+3] = W_Data[7:0];
            end else if (HalfWord) begin
                // Write 16-bit halfword (2 bytes)
                mem[Instruction_Address] = W_Data[15:8];
                mem[Instruction_Address+1] = W_Data[7:0];
            end else if (OneByte) begin
                // Write 8-bit byte
                mem[Instruction_Address] = W_Data[7:0];
            end
        end else begin
            R_Data = 0; // Default to 0 when no read/write
        end
    end

endmodule
