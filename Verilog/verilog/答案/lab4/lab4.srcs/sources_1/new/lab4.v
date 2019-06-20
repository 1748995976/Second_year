`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 20:35:28
// Design Name: 
// Module Name: main
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module path(clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,NEXT_ZERO);
    parameter WIDTH = 8;
    output [WIDTH-1:0] NEXT_ZERO;
    input clk,rst,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL;
    wire [WIDTH-1:0] a1,b1,s1,b2,d1,a2,d2,o2,s2,d3;
    assign a2 = 1;
    assign b2 = 0;
    add #(WIDTH) add1(a1,b1,s1);
    add #(WIDTH) add2(a2,o2,s2); 
    mux #(WIDTH) mux1(s1,b2,SUM_SEL,d1);
    mux #(WIDTH) mux2(b1,b2,NEXT_SEL,d2);
    mux #(WIDTH) mux3(s2,o2,A_SEL,d3);
    register #(WIDTH) register1(d1,LD_SUM,clk,rst,a1);
    register #(WIDTH) register2(d2,LD_NEXT,clk,rst,o2);
    ram #(WIDTH) ram1(d3,b1);
    compare #(WIDTH) compare1(d2,NEXT_ZERO);
endmodule
