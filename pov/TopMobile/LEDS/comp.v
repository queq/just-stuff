
`timescale 1ns / 1ps
module comp (in_comp, Z);
	input [4:0]	in_comp;
	output reg Z;

    always @(in_comp) begin
		if (in_comp == 5'b00000) Z <= 1'b1;
		else Z <= 1'b0;
	end
endmodule
