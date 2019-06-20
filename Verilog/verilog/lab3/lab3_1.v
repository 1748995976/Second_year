`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: lab1
//////////////////////////////////////////////////////////////////////////////////


module divider(clk, clk_N);
input clk;                      // ϵͳʱ��
output clk_N;                   // ��Ƶ���ʱ��
parameter N = 100_000_000;      // 1Hz��ʱ��,N=fclk/fclk_N
reg [31:0] counter;             /* ������������ͨ������ʵ�ַ�Ƶ��
                                   ����������0������(N/2-1)ʱ��
                                   ���ʱ�ӷ�ת������������ */
reg s = 0;
assign clk_N = s;                                   
always @(posedge clk)  begin    // ʱ��������
                              // ����ʵ��
	if(!clk)
		counter = 0;
	else if(counter==N/2-1)
		begin
			counter <=0;
			s <= ~s;
		end
	else
		counter <= counter+1;
end                           
endmodule


