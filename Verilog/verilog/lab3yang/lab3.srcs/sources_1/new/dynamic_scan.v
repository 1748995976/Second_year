`timescale 1ns / 1ps

module dynamic_scan(clk, SEG, AN);
input clk;
output [7:0] SEG;
output [7:0] AN;
wire clk_N;
wire [2:0] num;
wire [3:0] code;
    divider #(100_000_000) DV(clk, clk_N);
    counter COUN(clk_N, num);
    decoder3_8 D38(num, AN);
    rom8x4 ROM(num, code);
    pattern PT(code, SEG);
    
endmodule
