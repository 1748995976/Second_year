`timescale 1ns / 1ps

module memory(addr,data);
    parameter N=8;
    parameter SIZE=16;
    input [N-1:0]addr;
	output [N-1:0] data;
	
    reg [N-1:0]mem[0:SIZE-1] = {
            32'h00000003,
            32'h00000002,
            32'h00000000,
            32'h00000007,
            32'h00000004,
            32'h00000000,
            32'h00000000,
            32'h0000000b,
            32'h00000006,
            32'h00000000,
            32'h00000000,
            32'h00000000,
            32'h00000008,
            32'h00000000,
            32'h00000000,
            32'h00000000
        };
//	initial
//	   begin
//            $readmemh("C:\verilog\lab4\lab4\lab4.srcs\sources_1\imports\lab4\init.txt", mem);	
//       end
    assign data = mem[addr];
endmodule
