`timescale 1ns / 1ps
module comp_1 (vuelta, top_1);
	input [2:0]	vuelta;
	output reg top_1;

    always @(vuelta) begin
		if (vuelta==3'b101) top_1 <= 1'b1;//para camb top vueltas
		else top_1 <= 1'b0;
	end
endmodule
