`timescale 1ns / 1ps

module FSM(start,clk,rst,LD_SUM,LD_NEXT,A_SEL,NEXT_SEL,SUM_SEL,NEXT_ZERO,done);
   parameter START = 0,COMPUTE_SUM = 1,GET_NEXT = 2,DONE = 3;
   input clk,rst,start,NEXT_ZERO;
   output A_SEL,NEXT_SEL,SUM_SEL,LD_SUM,LD_NEXT,done;
   
   reg [1:0] State;
   reg [5:0] Value;
   
   assign {LD_SUM,LD_NEXT,SUM_SEL,NEXT_SEL,A_SEL,done} = Value[5:0];
   
   initial begin
        State <= START;
        Value <= 6'b000000;
   end
   
   always @(posedge clk) begin
    if(rst == 1) begin
        State <= START;
        Value <= 6'b000000;
    end
    else begin
        case(State)
            START:begin
                if(start == 0)begin
                    State <= START;
                    Value <= 6'b000000;
                end
                else begin
                    State <= COMPUTE_SUM;
                    Value = 6'b101110;
                end
            end
            COMPUTE_SUM:begin
                State <= GET_NEXT;
                Value = 6'b011100;
            end
            GET_NEXT:begin
                if(NEXT_ZERO == 0)begin
                    State <= COMPUTE_SUM;
                    Value = 6'b101110;
                end
                else begin
                    State <= DONE;
                    Value = 6'b000001;
                end
            end
            DONE:begin
                if(start == 0)begin
                    State <= START;
                    Value <= 6'b000000;
                end
                else begin
                    State <= DONE;
                    Value <= 6'b000001;
                end
            end
        endcase
     end
    end
                   
endmodule