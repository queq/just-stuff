`timescale 1ns / 1ps
module compn_ascci(
    input [3:0] n_ascci,
    output reg top_ascci
    );
always @(n_ascci) begin
		if (n_ascci==4'b1010) top_ascci <= 1'b1;
		else top_ascci <= 1'b0;
	end
endmodule


