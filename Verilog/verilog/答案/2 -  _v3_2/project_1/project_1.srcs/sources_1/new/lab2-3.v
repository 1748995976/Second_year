`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/08 21:24:54
// Design Name: 
// Module Name: lab2-3
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

module _7Seg_Driver_decoder(SEG,SW);
	input [15:0] SW;
	output [7:0] SEG;
	reg [7:0] S;

	assign SEG=S;

	always 
		@(SW[0] or SW[1] or SW[2] or SW[3]) begin
		if ({SW[3],SW[2],SW[1],SW[0]}==0) begin
			S='b11000000;
			end	
		else if ({SW[3],SW[2],SW[1],SW[0]}==1) begin
			S='b11111001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==2) begin
			S='b10100100;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==3) begin
			S='b10110000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==4) begin
			S='b10011001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==5) begin
			S='b10010010;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==6) begin
			S='b10000010;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==7) begin
			S='b11111000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==8) begin
			S='b10000000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==9) begin
			S='b10011000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==10) begin
			S='b10001000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==11) begin
			S='b10000011;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==12) begin
			S='b11000110;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==13) begin
			S='b10100001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==14) begin
			S='b10000110;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==15) begin
			S='b10001110;
		end
	end
endmodule

module _7Seg_Driver_selector(SW,AN);
	input [15:0] SW;
	output [7:0] AN;
	reg [7:0] A;
	assign  AN =~ A;
	

	always @(SW) begin
		if ({SW[15],SW[14],SW[13]}==0) begin
			A='b00000001;	
		end
		else if ({SW[15],SW[14],SW[13]}==1) begin
			A='b00000010;
		end
		else if ({SW[15],SW[14],SW[13]}==2) begin
			A='b00000100;
		end
		else if ({SW[15],SW[14],SW[13]}==3) begin
			A='b00001000;
		end
		else if ({SW[15],SW[14],SW[13]}==4) begin
			A='b00010000;
		end
		else if ({SW[15],SW[14],SW[13]}==5) begin
			A='b00100000;
		end
		else if ({SW[15],SW[14],SW[13]}==6) begin
			A='b01000000;
		end
		else if ({SW[15],SW[14],SW[13]}==7) begin
			A='b10000000;
		end
	end
endmodule

module _7Seg_Driver_Choice(SW, SEG, AN, LED);
    input [15:0] SW;       // 16位拨动开关
    output [7:0] SEG;      // 7段数码管驱动，低电平有效
    output [7:0] AN;       // 7段数码管片选信号，低电平有效
    output [15:0] LED;     // 16位LED显示
	assign LED[15:0] =SW[15:0] ;
	_7Seg_Driver_decoder(SEG,SW);
	_7Seg_Driver_selector(SW,AN);
endmodule