`timescale 1ns / 1ps

module rom8x4(addr, data);
input [2:0] addr;
output [3:0] data;

reg [3: 0] mem [7: 0];

initial   begin
    mem[0] = 0;
    mem[1] = 2;
    mem[2] = 4;
    mem[3] = 6;
    mem[4] = 8;
    mem[5] = 4'HA;
    mem[6] = 4'HC;
    mem[7] = 4'HE;
end     

assign data = mem[addr];
endmodule

