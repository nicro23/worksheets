
module RegisterFile (
    input wire clk,
    input wire reset,
    input wire write_enable,
    input wire [1:0] read_address,
    input wire [1:0] write_address,
    input wire [7:0] write_data,
    output wire [7:0] read_data
);
    reg [7:0] registers [3:0];
    //should go inside the always statement
    assign read_data = registers[read_address];
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            registers[0] <= 8'b00000000;
            registers[1] <= 8'b00000000;
            registers[2] <= 8'b00000000;
            registers[3] <= 8'b00000000;
        end else if (write_enable) begin
            registers[write_address] <= write_data;
        end
    end
endmodule

