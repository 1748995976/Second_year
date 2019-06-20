`timescale 1ns / 1ps

module decoder3_8(num, sel);
input [2: 0] num;
output [7:0] sel;
reg [7:0] A;
assign sel = ~A;

    always@(num)
    begin
        case (num)
            0 : A <= 8'b00000001;
            1 : A <= 8'b00000010;
            2 : A <= 8'b00000100;
            3 : A <= 8'b00001000;
            4 : A <= 8'b00010000;
            5 : A <= 8'b00100000;
            6 : A <= 8'b01000000;
            7 : A <= 8'b10000000;
        endcase
    end
endmodule
