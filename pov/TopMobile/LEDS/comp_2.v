`timescale 1ns / 1ps
module comp_2 (T, top_2); //corrimientos 0 a 15
	input [3:0]	T;
	output reg top_2;

    always @(T) begin
		if (T == 4'b1111) top_2 <= 1'b1;//camb top corrim
		else top_2 <= 1'b0;
	end
endmodule
