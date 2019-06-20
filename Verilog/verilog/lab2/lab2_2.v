module _7Seg_Driver_decoder(SEG,SW);
	input [15:0] SW;
	output [7:0] SEG;
	reg [7:0] S;

	assign SEG=S;

	always @(SW) 
	begin
		case(SW[3:0])
		0:S='b11000000;
		1:S='b11111001;
		2:S='b10100100;
		3:S='b10110000;
		4:S='b10011001;
		5:S='b10010010;
		6:S='b10000010;
		7:S='b11111000;
		8:S='b10000000;
		9:S='b10011000;
		10:S='b10001000;
		11:S='b10000011;
		12:S='b11000110;
		13:S='b10100001;
		14:S='b10000110;
		15:S='b10001110;
		endcase
	end
endmodule

module _7Seg_Driver_selector(SW,AN);
	input [15:0] SW;
	output [7:0] AN;
	reg [7:0] A;
	assign  AN =~ A;
	

	always
    @(SW) begin
		if ({SW[15],SW[14],SW[13]}==0) begin
			A='b00000001;	
		end
		else if ({SW[15],SW[14],SW[13]}==1) begin
			A='b00000010;
		end
		else if ({SW[15],SW[14],SW[13]}==2) begin
			A='b00000100;
		end
		else if ({SW[15],SW[14],SW[13]}==3) begin
			A='b00001000;
		end
		else if ({SW[15],SW[14],SW[13]}==4) begin
			A='b00010000;
		end
		else if ({SW[15],SW[14],SW[13]}==5) begin
			A='b00100000;
		end
		else if ({SW[15],SW[14],SW[13]}==6) begin
			A='b01000000;
		end
		else if ({SW[15],SW[14],SW[13]}==7) begin
			A='b10000000;
		end
	end
endmodule

module _7Seg_Driver_Choice(SW, SEG, AN, LED);
	input [15:0] SW;   // 16位拨动开�?
	output [7:0] SEG;  // 7段数码管驱动，低电平有效
	output [7:0] AN;// 7段数码管片�?�信号，低电平有�?
	output [15:0] LED;   // 16位LED显示

	assign LED[15:0] =SW[15:0] ;
	_7Seg_Driver_decoder(SEG,SW);
	_7Seg_Driver_selector(SW,AN);
endmodule
