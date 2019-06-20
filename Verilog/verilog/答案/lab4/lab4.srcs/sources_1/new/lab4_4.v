`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 20:01:30
// Design Name: 
// Module Name: register
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


module register(A,LD,CLK,RST,O);
parameter WIDTH = 8;
input [WIDTH-1:0] A;
input LD,CLK,RST;
output reg [WIDTH-1:0] O;
always@(posedge CLK)begin
    if(RST)
        O <= 0;
    else if(LD)
        O <= A;    
end
endmodule
