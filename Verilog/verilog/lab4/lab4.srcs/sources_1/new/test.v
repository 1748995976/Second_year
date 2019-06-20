`timescale 1ns / 1ps

module test();
    wire Done;
    reg clk,rst,start;
    wire [31:0] sum_out;
    
    initial begin
        clk <= 0;
        start <= 1;
        rst <= 0;
    end
    
    autooperate
        a1(clk,rst,start,Done,sum_out);
        
    always begin
        #10 clk = ~clk;
    end
    
endmodule
