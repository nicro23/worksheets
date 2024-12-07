module DataMemory (
    input [31:0] Address,        // 32-bit address to fetch or store data
    input [31:0] WriteData,      // 32-bit data to write to memory
    input MemRead,               // Control signal for read operation
    input MemWrite,              // Control signal for write operation
    input ByteEnable,            // Enable byte access
    input HalfwordEnable,        // Enable halfword access
    input WordEnable,            // Enable word access
    output reg [31:0] ReadData   // 32-bit data fetched from memory
);

    // Declare memory to store 8-bit bytes (128 words, 4 bytes each = 512 bytes total)
    reg [7:0] memory [0:511];    // 512 bytes of memory

    // Initial block to load some test data into memory
    initial begin
        // Initialize all memory locations to 0 (for simplicity)
        for (integer i = 0; i < 512; i = i + 1) begin
            memory[i] = 8'b0;   // Clear all memory bytes
        end
        
        // Example data (in hexadecimal format):
        memory[0] = 8'h12; // Byte 0x0
        memory[1] = 8'h34; // Byte 0x1
        memory[2] = 8'h56; // Byte 0x2
        memory[3] = 8'h78; // Byte 0x3
        
        memory[4] = 8'h9A; // Byte 0x4
        memory[5] = 8'hBC; // Byte 0x5

    end

    // Data Memory Operation (Read/Write Logic)
    always @(*) begin
        if (MemRead) begin
            if (WordEnable) begin
                // Read a 32-bit word (4 bytes)
                ReadData = {memory[Address], memory[Address+1], memory[Address+2], memory[Address+3]};
            end else if (HalfwordEnable) begin
                // Read a 16-bit halfword (2 bytes)
                ReadData = {16'b0, memory[Address], memory[Address+1]};
            end else if (ByteEnable) begin
                // Read a byte (8 bits)
                ReadData = {24'b0, memory[Address]};
            end
        end else if (MemWrite) begin
            if (WordEnable) begin
                // Write a 32-bit word (4 bytes)
                memory[Address] = WriteData[31:24];
                memory[Address+1] = WriteData[23:16];
                memory[Address+2] = WriteData[15:8];
                memory[Address+3] = WriteData[7:0];
            end else if (HalfwordEnable) begin
                // Write a 16-bit halfword (2 bytes)
                memory[Address] = WriteData[15:8];
                memory[Address+1] = WriteData[7:0];
            end else if (ByteEnable) begin
                // Write a byte (8 bits)
                memory[Address] = WriteData[7:0];
            end
        end else begin
            ReadData = 32'b0; // Default state (no read or write)
        end
    end

endmodule
