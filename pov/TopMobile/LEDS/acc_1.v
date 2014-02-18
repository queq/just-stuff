`timescale 1ns / 1ps
module acc_1(vuelta, clk, add_1, reset_1);//vueltas
	input 		clk;
	input 		add_1;
	input			reset_1; 
	output reg [2:0] vuelta;
	reg [2:0] temp;
always @(posedge clk) begin
		if (reset_1 == 1)	temp <= 3'b000;
		else if (add_1 == 1) temp <= temp+1;
			else temp<=temp;
		end	
always @(temp) begin
		vuelta <= temp;
	end
endmodule
