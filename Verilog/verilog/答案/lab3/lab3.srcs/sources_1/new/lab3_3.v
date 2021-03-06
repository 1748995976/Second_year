`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2019/05/15 20:12:10
// Design Name: 
// Module Name: lab3_3
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


module rom8x4(addr, data);
input [2:0] addr;           // 地址
output [3:0] data;          // 地址addr处存储的数据 

reg [3: 0] mem [7: 0];      //  8个4位的存储器
reg [3: 0] data;
initial   begin             // 初始化存储器
    mem[0] = 4'b0000;
    mem[1] = 4'b0010;
    mem[2] = 4'b0100;
    mem[3] = 4'b0110;
    mem[4] = 4'b1000;
    mem[5] = 4'b1010;
    mem[6] = 4'b1100;
    mem[7] = 4'b1110;
end     
    // 读取addr单元的值输出     
always@(addr[2:0] )begin
    case(addr[2:0])
    3'b000: data = mem[0];
    3'b001: data = mem[1];
    3'b010: data = mem[2];
    3'b011: data = mem[3];
    3'b100: data = mem[4];
    3'b101: data = mem[5];
    3'b110: data = mem[6];
    3'b111: data = mem[7];
    endcase 
end                 
endmodule

