
module adder(input a,input b, input cin, output s, output cout);

    assign s = a ^ b ^ cin;
    assign cout = a&b | cin & (a^b);
endmodule

module multi_adder(input a0,a1,a2,a3,b0,b1,b2,b3,cin,output s0,s1,s2,s3,c3,c0,c1,c2);

    // input a0,a1,a2,a3,b0,b1,b2,b3,cin;
    // wire s0,s1,s2,s3,c0,c1,c2,c3;
    adder f1 (a0,b0,cin,s0,c0);
    adder f2 (a1,b1,c0,s1,c1);
    adder f3 (a2,b2,c1,s2,c2);
    adder f4 (a3,b3,c2,s3,c3);  
endmodule