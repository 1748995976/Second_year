`timescale 1ns / 1ps

module autooperate(clk,rst,start,Done,sum_out);
    parameter N = 32;
    input clk,rst,start;
    output Done;
    output [N-1:0] sum_out;
    wire NEXT_ZERO;
    wire A_SEL,NEXT_SEL,SUM_SEL,LD_SUM,LD_NEXT;
    FSM
        F1(start,clk,rst,LD_SUM,LD_NEXT,A_SEL,NEXT_SEL,SUM_SEL,NEXT_ZERO,Done);
    datapath
        d1(clk,rst,LD_SUM,LD_NEXT,A_SEL,NEXT_SEL,SUM_SEL,NEXT_ZERO,sum_out);
endmodule
