`timescale 1ns / 1ps
module lsrB (clk, shift, load, out_B, lsb_B);
	input 				clk;
	input 				load;
	input 				shift;
	output reg [4:0] 	out_B;
	output reg 		lsb_B;
	parameter B=5'b10000;
	reg [4:0] 		tmp;

	always @(posedge clk) begin
		if (load == 1) tmp <= B;     
  		else if (shift == 1) tmp <= {1'b0,tmp[4:1]};
		else tmp <= tmp;
    end

	always @(tmp) begin
		out_B <= tmp;
		lsb_B <= tmp[0];
	end
endmodule
