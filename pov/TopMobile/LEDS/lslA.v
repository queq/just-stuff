`timescale 1ns / 1ps
module lslA(in_A, clk, load, shift, out_A);
	input [6:0]			in_A;	
	input 				clk;
	input 				load;
	input 				shift;
  	output reg [10:0] 	out_A;
	reg [10:0]			tmp;

	always @(posedge clk) begin
		if (load == 1) tmp <= {4'b000,in_A};     
		else if (shift == 1) tmp <= {tmp[9:0],1'b0};
    	else tmp <= tmp;
	end

	always @(tmp) out_A <= tmp;

endmodule       
