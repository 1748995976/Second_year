module _7Seg_Driver_Decode(SW, SEG, AN, LED);
	input [15:0] SW;   // 16位拨动开�?
	output[7:0] SEG;  // 7段数码管驱动，低电平有效
	output [7:0] AN;// 7段数码管片�?�信号，低电平有�?
	output [15:0] LED;   // 16位LED显示
    reg [7:0] s;
	assign LED[15:0] =SW[15:0] ;
	assign AN[7:0] =~SW[15:8] ;
    assign SEG=s;
	always 
		@(SW[0] or SW[1] or SW[2] or SW[3]) begin
		if ({SW[3],SW[2],SW[1],SW[0]}==0) begin
			s[7:0]='b11000000;
			end	
		else if ({SW[3],SW[2],SW[1],SW[0]}==1) begin
			s[7:0]='b11111001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==2) begin
			s[7:0]='b10100100;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==3) begin
			s[7:0]='b10110000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==4) begin
			s[7:0]='b10011001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==5) begin
			s[7:0]='b10010010;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==6) begin
			s[7:0]='b10000010;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==7) begin
			s[7:0]='b11111000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==8) begin
			s[7:0]='b10000000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==9) begin
			s[7:0]='b10011000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==10) begin
			s[7:0]='b10001000;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==11) begin
			s[7:0]='b10000011;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==12) begin
			s[7:0]='b11000110;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==13) begin
			s[7:0]='b10100001;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==14) begin
			s[7:0]='b10000110;
		end
		else if ({SW[3],SW[2],SW[1],SW[0]}==15) begin
			s[7:0]='b10001110;
		end
	end


endmodule
