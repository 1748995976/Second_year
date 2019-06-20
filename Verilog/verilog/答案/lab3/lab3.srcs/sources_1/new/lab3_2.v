`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/15 20:02:33
// Design Name: 
// Module Name: lab3_2
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


module counter(clk, out);
input clk;                    // 计数时钟
output [2:0] out;             // 计数值
reg [2:0] out;
always @(posedge clk)  begin  // 在时钟上升沿计数器加1
    out = out + 1;          // 功能实现
end                           
endmodule

