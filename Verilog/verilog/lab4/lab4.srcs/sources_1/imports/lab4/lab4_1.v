`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: lab4_1
//////////////////////////////////////////////////////////////////////////////////


module datapath(clk,rst,LD_SUM,LD_NEXT,A_SEL,NEXT_SEL,SUM_SEL,NEXT_ZERO,SUM_OUT);
    parameter N = 32;
    input clk,rst,A_SEL,NEXT_SEL,SUM_SEL;
    input LD_SUM,LD_NEXT;
    output NEXT_ZERO;
    output [N-1:0]SUM_OUT;
    
    wire[N-1:0] a1,b1,D1,D2,D3,O2,s1,s2;
    wire[N-1:0] a2=1;
    wire[N-1:0] c=0;
    
	assign SUM_OUT = a1;
	adder #(N) adder1(a1,b1,s1);
	adder #(N) adder2(a2,O2,s2);
	mulchoose #(N) chooser1(c,s1,SUM_SEL,D1);
	mulchoose #(N) chooser2(c,b1,NEXT_SEL,D2);
	mulchoose #(N) chooser3(O2,s2,A_SEL,D3);
	register #(N) reg1(clk,D1,a1,LD_SUM,rst);
	register #(N) reg2(clk,D2,O2,LD_NEXT,rst);
	compare #(N) com1(D2,NEXT_ZERO);
	memory #(N) mem1(D3,b1);
	   
	
endmodule