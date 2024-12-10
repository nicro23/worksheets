module RegisterFile (
    input [31:0] R_Address,    // 32-bit address to fetch data
    input [31:0] W_Address,    // 32-bit address to store data
    input read_enable,          // Control signal for read operation
    input write_enable,         // Control signal for write operation
    input [7:0] WriteData,      // 8-bit data to write to memory
    output reg [7:0] ReadData   // 8-bit data fetched from memory
);

    // Declare registers to store 4 8-bit bytes
    reg [7:0] register [0:3];    // 4 bytes of memory

    // Initial block to reset registers
    initial begin
        // Reset all register locations to 0
        for (integer i = 0; i < 8; i++) begin
            register[i] = 8'b0;   // Clear all
        end
    end

    // Data Memory Operation (Read/Write Logic)
    always @(*) begin
        if (read_enable) begin
                // Read a byte (8 bits)
                ReadData = {register[R_Address]};
        end else if (write_enable) begin
                // Write a byte (8 bits)
                register[W_Address] = WriteData[7:0];
        end else begin
            ReadData = 8'b0; // Default state (no read or write)
        end
    end

endmodule
