`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 20:19:01
// Design Name: 
// Module Name: ram
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


module ram(addr,data);
    parameter DWIDTH = 8;
    parameter AWIDTH = 8;
    input [AWIDTH-1:0] addr;
    output [DWIDTH-1:0] data;
    reg [AWIDTH-1:0] ram [DWIDTH-1:0];
    assign data = ram[addr];
    initial $readmemb ("data.txt",ram);
endmodule
