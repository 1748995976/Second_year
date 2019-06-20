`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Create Date: 2019/05/15 20:13:03
//////////////////////////////////////////////////////////////////////////////////

module divider(clk, clk_N);
input clk;
output clk_N;
reg cn = 0;
parameter N = 100_000_000;
reg [31:0] counter;

assign clk_N = cn;
always @(posedge clk)  begin
    counter <= counter + 1;
    if (counter >= N/2)
    begin
        counter <= 0;
        cn <= ~cn;
    end
end
endmodule

