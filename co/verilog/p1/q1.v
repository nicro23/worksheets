module ComCir1( input a, b, c, d, e,output y);
assign y = ((~(a | b)) | (c & d)) & e;
endmodule