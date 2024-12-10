`include "p1.v"

module p1_tb;

reg a0,a1,a2,a3,b0,b1,b2,b3,cin;
wire s0,s1,s2,s3,c0,c1,c2,c3;
multi_adder uut(a0,a1,a2,a3,b0,b1,b2,b3,cin,s0,s1,s2,s3,c3,c0,c1,c2);
initial begin
$dumpfile("p1_test2.vcd");
$dumpvars( 0, p1_tb);
$display("t|cin|a0|b0|s0|c0|a1|b1|s1|c1|a2|b2|s2|c2|a3|b3|s3|c3");
$monitor("%0t|%b  |%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b|%b", $time, cin,a0,b0,s0,c0,a1,b1,s1,c1,a2,b2,s2,c2,a3,b3,s3,c3);

for(integer i = 0; i<512; i++)
begin
    {a0,a1,a2,a3,b0,b1,b2,b3,cin} = i;
    #1;
end
end
endmodule