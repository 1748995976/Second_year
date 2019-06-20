`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 19:03:11
// Design Name: 
// Module Name: lab4_1
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


module add(A,B,C);
    parameter WIDTH = 8;
    input[WIDTH-1:0] A,B;
    output[WIDTH-1:0] C;
    wire [WIDTH-1:0] DATA;
    assign DATA = A + B;
    assign C = DATA[WIDTH-1:0];
endmodule
