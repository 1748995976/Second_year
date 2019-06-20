`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 19:44:31
// Design Name: 
// Module Name: mux
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


module mux(A,B,SEL,C);
    parameter WIDTH = 8;
    input [WIDTH-1:0] A,B;
    input SEL;
    output [WIDTH-1:0] C;
    reg [WIDTH-1:0] DATA;
    always@(SEL)begin
        if(SEL == 1)
           DATA = A;
        else
           DATA = B;    
    end
    assign C = DATA[WIDTH-1:0];
endmodule
