module Datapath (ALUOp, RegDst, MemtoReg, MemRead, MemWrite, IorD, RegWrite, IRWrite,
PCWrite, PCWriteCond, ALUSrcA, ALUSrcB, PCSource, opcode, clock); // the control inputs + clock
input [1:0] ALUOp, ALUSrcB, PCSource; // 2-bit control signals
input RegDst, MemtoReg, MemRead, MemWrite, IorD, RegWrite, IRWrite, PCWrite, PCWriteCond,
ALUSrcA, clock; // 1-bit control signals
output [5:0] opcode ;// opcode is needed as an output by control
reg [31:0] PC, Memory [0:1023], MDR,IR, ALUOut; // CPU state + some temporaries
wire [31:0] A,B,SignExtendOffset, PCOffset, ALUResultOut, PCValue, JumpAddr, Writedata, ALUAin,
ALUBin,MemOut; // these are signals derived from registers
wire [3:0] ALUCtl; //. the ALU control lines
wire Zero; //the Zero out signal from the ALU
wire[4:0] Writereg;// the signal used to communicate the destination register
initial PC = 0; //start the PC at 0
//Combinational signals used in the datapath
// Read using word address with either ALUOut or PC as the address source
assign MemOut = MemRead ? Memory[(IorD ? ALUOut : PC)>>2]:0;
assign opcode = IR[31:26];// opcode shortcut
// Get the write register address from one of two fields depending on RegDst
assign Writereg = RegDst ? IR[15:11]: IR[20:16];
// Get the write register data either from the ALUOut or from the MDR
assign Writedata = MemtoReg ? MDR : ALUOut;
// Sign-extend the lower half of the IR from load/store/branch offsets
assign SignExtendOffset = {{16{IR[15]}},IR[15:0]}; //sign-extend lower 16 bits;
// The branch offset is also shifted to make it a word offset
assign PCOffset = SignExtendOffset << 2;
// The A input to the ALU is either the rs register or the PC
assign ALUAin = ALUSrcA ? A : PC; //ALU input is PC or A
// Compose the Jump address
assign JumpAddr = {PC[31:28], IR[25:0],2'b00}; //The jump 
// Creates an instance of the ALU control unit (see the module defined in Figure C.5.16 on page C-38
// Input ALUOp is control-unit set and used to describe the instruction class as in Chapter 4
// Input IR[5:0] is the function code field for an ALU instruction
// Output ALUCtl are the actual ALU control bits as in Chapter 4
ALUControl alucontroller (ALUOp,IR[5:0],ALUCtl); //ALU control unit
// Creates a 3-to-1 multiplexor used to select the source of the next PC
// Inputs are ALUResultOut (the incremented PC) , ALUOut (the branch address), the jump target address
// PCSource is the selector input and PCValue is the multiplexor output
Mult3to1 PCdatasrc (ALUResultOut,ALUOut,JumpAddr, PCSource , PCValue);
// Creates a 4-to-1 multiplexor used to select the B input of the ALU
// Inputs are register B,constant 4, sign-extended lower half of IR, sign-extended lower half of IR << 2
// ALUSrcB is the selector input
// ALUBin is the multiplexor output
Mult4to1 ALUBinput (B,32'd4,SignExtendOffset,PCOffset,ALUSrcB,ALUBin);
// Creates a MIPS ALU
// Inputs are ALUCtl (the ALU control), ALU value inputs (ALUAin, ALUBin)
// Outputs are ALUResultOut (the 32-bit output) and Zero (zero detection output)
MIPSALU ALU (ALUCtl, ALUAin, ALUBin, ALUResultOut,Zero); //the ALU
// Creates a MIPS register file
// Inputs are
// the rs and rt fields of the IR used to specify which registers to read,
// Writereg (the write register number), Writedata (the data to be written), RegWrite (indicates a write), the clock
// Outputs are A and B, the registers read
registerfile regs (IR[25:21],IR[20:16],Writereg,Writedata,RegWrite,A,B,clock); //Register file
// The clock-triggered actions of the datapath
always @(posedge clock) begin if (MemWrite) Memory[ALUOut>>2] <= B; // Write memory--must be a store
ALUOut <= ALUResultOut; //Save the ALU result for use on a later clock cycle
if (IRWrite) IR <= MemOut; // Write the IR if an instruction fetch
MDR <= MemOut; // Always save the memory read value
// The PC is written both conditionally (controlled by PCWrite) and unconditionally
if (PCWrite || (PCWriteCond & Zero)) PC <=PCValue;
end
endmodule

module CPU (clock);
parameter LW = 6’b100011, SW = 6’b101011, BEQ = 6’b000100, J = 6’d2; //constants
input clock; reg [2:0] state;
wire [1:0] ALUOp, ALUSrcB, PCSource; wire [5:0] opcode;
wire RegDst, MemRead, MemWrite, IorD, RegWrite, IRWrite, PCWrite, PCWriteCond,
ALUSrcA, MemoryOp, IRWwrite, Mem2Reg;
// Create an instance of the MIPS datapath, the inputs are the control signals; opcode is only output
Datapath MIPSDP (ALUOp,RegDst,Mem2Reg, MemRead, MemWrite, IorD, RegWrite,
IRWrite, PCWrite, PCWriteCond, ALUSrcA, ALUSrcB, PCSource, opcode, clock);
initial begin state = 1; end // start the state machine in state 1
// These are the definitions of the control signals
assign IRWrite = (state==1);
assign Mem2Reg = ~ RegDst;
assign MemoryOp = (opcode==LW)|(opcode==SW); // a memory operation
assign ALUOp = ((state==1)|(state==2)|((state==3)&MemoryOp)) ? 2’b00 : // add
((state==3)&(opcode==BEQ)) ? 2’b01 : 2’b10; // subtract or use function code
assign RegDst = ((state==4)&(opcode==0)) ? 1 : 0;
assign MemRead = (state==1) | ((state==4)&(opcode==LW));
assign MemWrite = (state==4)&(opcode==SW);
assign IorD = (state==1) ? 0 : (state==4) ? 1 : X;
assign RegWrite = (state==5) | ((state==4) &(opcode==0));
assign PCWrite = (state==1) | ((state==3)&(opcode==J));
assign PCWriteCond = (state==3)&(opcode==BEQ);
assign ALUSrcA = ((state==1)|(state==2)) ? 0 :1;
assign ALUSrcB = ((state==1) | ((state==3)&(opcode==BEQ))) ? 2’b01 : (state==2) ? 2’b11 :
((state==3)&MemoryOp) ? 2’b10 : 2’b00; // memory operation or other
assign PCSource = (state==1) ? 2’b00 : ((opcode==BEQ) ? 2’b01 : 2’b10);
// Here is the state machine, which only has to sequence states
always @(posedge clock) begin // all state updates on a positive clock edge
case (state)
1: state = 2; //unconditional next state
2: state = 3; //unconditional next state
3: // third step: jumps and branches complete
state = ((opcode==BEQ) | (opcode==J)) ? 1 : 4;// branch or jump go back else next state
4: state = (opcode==LW) ? 5 : 1; //R-type and SW finish
5: state = 1; // go back
endcase
end
endmodule