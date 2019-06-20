`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/29 21:37:57
// Design Name: 
// Module Name: lab5
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


module control(clk,rst,start,next_zero,LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done);
    input clk,rst,start,next_zero;
    output reg LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done;
    always@(posedge clk)begin
        if(rst == 1 || start == 0)begin
            LD_SUM = 0;
            LD_NEXT = 0;
            SUM_SEL = 0;
            NEXT_SEL = 0;
            A_SEL = 0;
            done = 0;
        end    
        else begin
            LD_SUM = 1;
            LD_NEXT = 0;
            SUM_SEL = 1;
            NEXT_SEL = 1;
            A_SEL = 1;
            done = 0;
              
        end  
    end
endmodule
