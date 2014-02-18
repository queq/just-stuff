`timescale 1ns / 1ps
module acc_2(T, clk, add_2,reset_2); //corriminetos
	input 		clk;
	input 		add_2;
	input			reset_2; 
	output reg [3:0] T;
	reg [3:0] temp;
always @(posedge clk) begin
		if (reset_2 == 1) temp<=4'b0000;
		else if (add_2 == 1) temp <= temp+1;
		else temp<=temp;
	end	
always @(temp) begin
		T <= temp;
	end
endmodule
