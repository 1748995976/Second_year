`timescale 1ns / 1ps

module compare(a,s);
    parameter N = 8;
    input [N-1:0] a;
    output s;
    
    assign s = (a == 0);
endmodule