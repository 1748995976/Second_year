`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 19:31:22
// Design Name: 
// Module Name: compare
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


module compare(a,NEXT_ZERO);
    parameter WIDTH = 8;
    input [WIDTH-1:0] a;
    output NEXT_ZERO;
    reg NEXT_ZERO;
    always@(a)begin
        if(a == 0)
            NEXT_ZERO = 1;
        else 
            NEXT_ZERO = 0;    
    end
endmodule
