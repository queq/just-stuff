`timescale 1ns / 1ps
module cont_ascci(
output reg [3:0] n_ascci,
input clk,
input add_ascci,
input reset_ascci
 );//contador de pos caracteres 0:9
	reg [3:0] temp;
always @(posedge clk) begin
		if (reset_ascci == 1)	temp <= 4'b0000;
		else if (add_ascci == 1) temp <= temp+1;
			else temp<=temp;
		end	
always @(temp) begin
		n_ascci <= temp;
	end
endmodule
 

