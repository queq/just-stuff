`timescale 1ns / 1ps
module acumulador(in_A, clk, acc, reset, pp);
	input [10:0]		in_A;
	input 			clk;
	input 			acc;
	input 			reset; 
	output reg [10:0] 	pp;
	reg [10:0] 		temp;

	always @(posedge clk) begin
		if (reset == 1) temp = 11'b00000000000;
		else if (acc == 1) temp = temp + in_A;
		else temp = temp;
	end

	always @(temp) begin
		pp <= temp;
	end
endmodule
