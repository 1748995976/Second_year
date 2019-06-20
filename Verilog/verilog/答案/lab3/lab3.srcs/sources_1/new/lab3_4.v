`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/15 20:48:56
// Design Name: 
// Module Name: decoder3_8
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


module decoder3_8(num, sel);
input [2:0] num;       // ����ܱ�ţ�0~7
output [7:0] sel;       // 7�������Ƭѡ�źţ��͵�ƽ��Ч
                   // ����ʵ��
reg [7:0] sel;
always@(num[2:0]) begin
    case(num[2:0])
        3'b000 : sel = 8'b11111110;
        3'b001 : sel = 8'b11111101;
        3'b010 : sel = 8'b11111011;
        3'b011 : sel = 8'b11110111;
        3'b100 : sel = 8'b11101111;
        3'b101 : sel = 8'b11011111;
        3'b110 : sel = 8'b10111111;
        3'b111 : sel = 8'b01111111;
    endcase
end
endmodule

module pattern(code, patt);
input [3: 0] code;       // 16�������ֵ�4λ�����Ʊ���
output [7:0] patt;       // 7��������������͵�ƽ��Ч
                  // ����ʵ��
reg [7:0] patt;
always@(code[3:0]) begin
    case(code[3:0])
        4'b0000 : patt = 8'b11000000;
        4'b0001 : patt = 8'b11111001;
        4'b0010 : patt = 8'b10100100;
        4'b0011 : patt = 8'b10110000;
        4'b0100 : patt = 8'b10011001;
        4'b0101 : patt = 8'b10010010;
        4'b0110 : patt = 8'b10000010;
        4'b0111 : patt = 8'b11111000;
        4'b1000 : patt = 8'b10000000;
        4'b1001 : patt = 8'b10011000;
        4'b1010 : patt = 8'b10001000;
        4'b1011 : patt = 8'b10000011;
        4'b1100 : patt = 8'b11000110;
        4'b1101 : patt = 8'b10100001;
        4'b1110 : patt = 8'b10000110;
        4'b1111 : patt = 8'b10001110;
    endcase
end
endmodule


