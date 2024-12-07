`include "q1.v"

module q1_tb;
reg a,b,c,d,e;
wire y;
ComCir1 uut(a,b,c,d,e,y);

initial begin
$dumpfile("q1_tbb.vcd");
$dumpvars(0, q1_tb);
$monitor("time = %0t, e = %b, y = %b", $time, e, y);

for(integer i = 0; i < 32; i++)
begin
    {a,b,c,d,e} = i;
    #1;
end

$finish;
end

endmodule
