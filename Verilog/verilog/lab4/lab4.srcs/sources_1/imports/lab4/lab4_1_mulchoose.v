`timescale 1ns / 1ps

module mulchoose(a,b,sel,s);
    parameter N = 8;
    input [N-1:0] a;
    input [N-1:0] b;
    input sel;
    output [N-1:0] s;
    
    assign s = sel ? b : a;
endmodule