`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/15 21:10:09
// Design Name: 
// Module Name: lab3_6
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


module dynamic_scan(clk,  SEG, AN);
input clk;              // ϵͳʱ��
output wire [7:0] SEG;  		// �ֱ��ӦCA��CB��CC��CD��CE��CF��CG��DP
output wire [7:0] AN;        // 8λ�����Ƭѡ�ź�
                  // ����ʵ��
wire clk_N;
wire [2:0] num;
wire [3:0] data;
divider #(100) ttt(clk,clk_N);
//divider(clk,clk_N);
counter(clk_N,num);
rom8x4(num,data);
decoder3_8(num,AN);
pattern(data,SEG);
endmodule

