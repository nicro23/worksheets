`include "q1.v"

module q1_b;
reg a,b,c,d,e;
wire y;
ComCir1 uut(.a(a),.b(b),.c(c),.d(d),.e(e),.y(y));

initial begin
$dumpfile = ("q1_tb.vcd");
$dumpvars = (0, q1_b);
$monitor = ("time = %0t, e = %b, y = %b", $time, e, y);

for(integer i = 0; i < 32; i++)
begin
    {a,b,c,d,e} = i;
    #1;
end

$finish;
end

endmodule
