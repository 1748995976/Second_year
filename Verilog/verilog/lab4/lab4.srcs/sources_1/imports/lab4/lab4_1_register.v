`timescale 1ns / 1ps

module register(clk,d,q,load,rst);
    parameter N = 8;
    input clk;
    input rst;
    input load;
    input [N-1:0] d;
    output reg [N-1:0] q = 0;
    
    always @ (posedge clk)
    begin
        if(rst == 1)
            q <= 0;
        else if(load == 1)
            q <= d; 
    end
endmodule

