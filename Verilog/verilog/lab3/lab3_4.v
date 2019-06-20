`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: lab1
//////////////////////////////////////////////////////////////////////////////////


module decoder3_8(num, sel);
input [2: 0] num;       // 数码管编号：0~7
output [7:0] sel;       // 7段数码管片选信号，低电平有效
always
    @(SW) begin
		if ({num[2],num[1],num[0]}==0) begin
			sel='b00000001;	
		end
		else if ({num[2],num[1],num[0]}==1) begin
			sel='b00000010;
		end
		else if ({num[2],num[1],num[0]}==2) begin
			sel='b00000100;
		end
		else if ({num[2],num[1],num[0]}==3) begin
			sel='b00001000;
		end
		else if ({num[2],num[1],num[0]}==4) begin
			sel='b00010000;
		end
		else if ({num[2],num[1],num[0]}==5) begin
			sel='b00100000;
		end
		else if ({num[2],num[1],num[0]}==6) begin
			sel='b01000000;
		end
		else if ({num[2],num[1],num[0]}==7) begin
			sel='b10000000;
		end
	end                  // 功能实现
endmodule

module pattern(code, patt);
input [3: 0] code;       // 16进制数字的4位二进制编码
output [7:0] patt;       // 7段数码管驱动，低电平有效
always 
		@(code[0] or code[1] or code[2] or code[3]) begin
		if ({code[3],code[2],code[1],code[0]}==0) begin
			patts[7:0]='b11000000;
			end	
		else if ({code[3],code[2],code[1],code[0]}==1) begin
			patt[7:0]='b11111001;
			end
		else if ({code[3],code[2],code[1],code[0]}==2) begin
			patt[7:0]='b10100100;
			end
		else if ({code[3],code[2],code[1],code[0]}==3) begin
			patt[7:0]='b10110000;
			end
		else if ({code[3],code[2],code[1],code[0]}==4) begin
			patt[7:0]='b10011001;
			end
		else if ({code[3],code[2],code[1],code[0]}==5) begin
			patt[7:0]='b10010010;
			end
		else if ({code[3],code[2],code[1],code[0]}==6) begin
			patt[7:0]='b10000010;
			end
		else if ({code[3],code[2],code[1],code[0]}==7) begin
			patt[7:0]='b11111000;
			end
		else if ({code[3],code[2],code[1],code[0]}==8) begin
			patt[7:0]='b10000000;
			end
		else if ({code[3],code[2],code[1],code[0]}==9) begin
			patt[7:0]='b10011000;
			end
		else if ({code[3],code[2],code[1],code[0]}==10) begin
			patt[7:0]='b10001000;
			end
		else if ({code[3],code[2],code[1],code[0]}==11) begin
			patt[7:0]='b10000011;
			end
		else if ({code[3],code[2],code[1],code[0]}==12) begin
			patt[7:0]='b11000110;
			end
		else if ({code[3],code[2],code[1],code[0]}==13) begin
			patt[7:0]='b10100001;
			end
		else if ({code[3],code[2],code[1],code[0]}==14) begin
			patt[7:0]='b10000110;
			end
		else if ({code[3],code[2],code[1],code[0]}==15) begin
			patt[7:0]='b10001110;
			end
	end                      // 功能实现
endmodule



