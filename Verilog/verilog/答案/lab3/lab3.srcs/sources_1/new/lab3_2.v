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
input clk;                    // ����ʱ��
output [2:0] out;             // ����ֵ
reg [2:0] out;
always @(posedge clk)  begin  // ��ʱ�������ؼ�������1
    out = out + 1;          // ����ʵ��
end                           
endmodule

