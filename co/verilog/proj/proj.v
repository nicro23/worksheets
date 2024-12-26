module Instruction_Memory (
    input [31:0] Instruction_Address,
    output reg [31:0] Instruction
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
        
        //examples
        //add (add $t2, $t0, $t1)
        // 000000 01000 01001 01010 00000 100000 
        mem[0] = 8'h01;
        mem[1] = 8'h09;
        mem[2] = 8'h50;
        mem[3] = 8'h20;

        //sub (sub $t2, $t0, $t1)
        // 000000 01000 01001 01011 00000 100010 
        mem[4] = 8'h01;
        mem[5] = 8'h09;
        mem[6] = 8'h58;
        mem[7] = 8'h22;
        
        //lw (lw $t1 , 0[$t2])
        // 100011 01011 01101 0000 0000 0000 0000
        mem[0] = 8'h8D;
        mem[1] = 8'h6D;
        mem[2] = 8'h00;
        mem[3] = 8'h00;
        
        //beq 
        // 0001 00 01 010 0 1011 0000 0000 0000 0100
        mem[8] = 8'h11;  // (opcode )
        mem[9] = 8'h4B;    // (rt register)
        mem[10] = 8'h00;    // (rs register)
        mem[11] = 8'h04;    // (immediate value)
        
    end

    // Instruction Fetch Logic 
    always @(*) 
    begin
        // read 4 bytes after each other to form a 32-bit instruction 
        Instruction = {mem[Instruction_Address[31:0]], mem[Instruction_Address[31:0] + 1], mem[Instruction_Address[31:0] + 2], mem[Instruction_Address[31:0] + 3]}; 
    end

endmodule

//wire or reg? or none
module RegisterFile (
    input wire clk,
    input wire write_enable,
    input wire [4:0] rs_address,
    input wire [4:0] rt_address,
    input wire [4:0] rd_address,
    input wire [31:0] rd_data,
    output wire [31:0] rs_data,
    output wire [31:0] rt_data
);
    //shelt el reset 7seit msh m7tageino idk
    reg [31:0] registers [0:31];
    initial begin
        for(integer i = 0; i < 32; i++) begin
                registers[i] = 0;
            end
        registers[8] = 32'd2;
        registers[9] = 32'd1;
        registers[11] = 32'd4;
    end
    assign rs_data = registers[rs_address];
    assign rt_data = registers[rt_address];
    always @(posedge clk) begin
        if (write_enable) begin
            registers[rd_address] <= rd_data;
        end
    end
endmodule

module alu (input [31:0] a, input [31:0] b, input [5:0] func_code, input [4:0] shamt, output reg [31:0] c, output zero);

assign zero = (a - b)? 0 : 1;
always @(*)begin
    case(func_code)
        6'd36: c = a&b;
        6'd37: c = a|b;
        6'd32: c = a+b;
        6'd34: c = a-b;
        6'd42: if(a<b) c = 1; else c = 0;
        default: c = 0;
    endcase
end
endmodule

module DataMemory (
    input wire clk,
    input [31:0] Instruction_Address,   // Address for read/write operation
    input [31:0] W_Data,                // Data to write to memory
    output reg [31:0] R_Data,           // Data read from memory
    input Read_M,                       // Read control signal
    input Write_M                      // Write control signal
);

    // Memory storage: 512 words
    reg [31:0] mem [0:511];    

    initial 
    begin
        // Clear memory
        for (integer k = 0; k < 512; k = k + 1) 
            mem[k] = 0;   
        mem[0] = 32'd4;
    end
    // Read/Write Logic
    always @(posedge clk) begin
        if (Read_M) begin
                // Read 32-bit word (4 bytes)
                R_Data = {mem[Instruction_Address], mem[Instruction_Address+1], mem[Instruction_Address+2], mem[Instruction_Address+3]};
        end else if (Write_M) begin
                // Write 32-bit word (4 bytes)
                mem[Instruction_Address] = W_Data[31:24];
                mem[Instruction_Address+1] = W_Data[23:16];
                mem[Instruction_Address+2] = W_Data[15:8];
                mem[Instruction_Address+3] = W_Data[7:0];
        end else begin
            R_Data = 0; // Default to 0 when no read/write
        end
    end

endmodule

//aluop sucks {missing}
module MIPS_datapath(input clk,input write_enable, write_memory, read_memory, branch);
wire [31:0] PC, incremented_PC;
wire [31:0] instruction, BTA;
wire [31:0] signextend;
wire [4:0] rs_a, rt_a, rd_a, shamt;
wire [31:0] rs_data, rt_data, rd_data, Mem_address, write_data, read_data;
wire [31:0] A, B;
wire [31:0] aluout;
wire [5:0] aluop, funct;
reg [2:0] state;
reg PC_init;
wire zero;
initial begin
PC_init = 1;
state = 0;
end
//state 0: fetch instruction
assign PC = (PC_init) ? -4 : 
((state == 2 && aluop == 6'd4 && zero) ? BTA : (state == 0) ? PC + 4 : PC);
Instruction_Memory IM (PC,instruction);
//state 1: decode instruction
assign aluop = (state == 1)? instruction[31:26] : aluop;
assign rs_a = (state == 1) ? instruction[25:21] : rs_a;
assign rt_a = (state == 1) ? instruction[20:16] : rt_a;
assign rd_a =  (state == 1) ? ((aluop == 0) ? instruction[15:11]: rt_a): rd_a;
RegisterFile RF (clk, write_enable, rs_a, rt_a, rd_a, rd_data, rs_data, rt_data);
assign funct = (state == 1) ? 
((aluop == 6'd43 || aluop == 6'd35) ? 6'd32 : 
((aluop == 6'd4) ? 6'd34 : instruction[5:0])) : funct;
assign shamt = (state == 1) ? ((aluop == 0) ? instruction[10:6] : 0) : shamt;
assign signextend = (state == 1) ? 
((aluop == 0) ? 0 : ({{16{instruction[15]}},instruction[15:0]})) : signextend;
//state 2: execute 
assign A = (state == 2) ? rs_data : A;
// assign A = rs_data;
assign B = (state == 2) ? ((aluop == 0) ? rt_data : signextend) : B;
assign BTA = (state == 2) ? (PC + signextend << 2): BTA;
alu  ALU (A, B, funct, shamt, aluout, zero);
//state 3: read/write back
assign Mem_address = (state == 3) ? aluout : Mem_address;
assign write_data = (state == 3) ? rs_data : write_data;
DataMemory DM (clk, Mem_address, write_data, read_data, read_memory, write_memory);
assign rd_data = (state == 3) ? ((aluop == 0) ? aluout : read_data ) : rd_data; 
always @(posedge clk)
case (state)
//fetch instruction
0:
begin
    //should create a new instance
    //alu(pc,4,6'd32,0,pc,zero);
    PC_init = 0;
    state = 1;
end
//decode instruction
1:
begin
    state = 2;
end
//execute instruction
2:
begin
    // state = (aluop == 6'd4 && zero) ? 1 : 3;
    state = 3;
end
//memory write/read
3:
begin
    state = 4;
end
4:
begin
    state = 0;
end
endcase
endmodule