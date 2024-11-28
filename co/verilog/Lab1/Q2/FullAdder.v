module full_adder(
    input A,     // First bit
    input B,     // Second bit
    input Cin,   // Carry-in
    output Sum,  // Sum
    output Cout  // Carry-out
);
    // Logic for Full Adder
    assign Sum = A ^ B ^ Cin;        // XOR for Sum
    assign Cout = ((A ^ B) & Cin) | (A & B); // Carry-out
endmodule
