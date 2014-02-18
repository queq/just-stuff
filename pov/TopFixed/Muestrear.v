module Muestrear(ClkKB, NewDataKB, Clk , Reset);
	input ClkKB,Clk , Reset;
	output reg NewDataKB;
	reg [2:0]state;
	parameter Idle = 3'h0;
	parameter NegEdgeTest  = 3'h1;
	parameter NegEdge  = 3'h2;
	parameter Down = 3'h3;
	parameter PosEdgeTest  = 3'h4;
always @(posedge Clk) begin
	if (Reset)
		state = Idle;
	else 
		case(state)
			Idle:begin
				if (ClkKB)	state = Idle;
				else state = NegEdgeTest;		
			end
			NegEdgeTest:begin
				if (ClkKB)	state = Idle;
				else state = NegEdge;				
			end
			NegEdge: state = Down;							
			Down:begin
				if (ClkKB)	state = PosEdgeTest;
				else state = Down;				
			end
			PosEdgeTest:begin
				if (ClkKB)	state = Idle;
				else state = Down;				
			end
			default: state = Idle;
		endcase
	end
always @(state) begin
	if (state==NegEdge) NewDataKB=1;
	else NewDataKB=0;
end

endmodule
