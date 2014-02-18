`timescale 1ns / 1ps
module cont_col(
    input clk,
    input add_col,
    input reset_col,
    output reg [3:0]col
    );
reg [3:0] temp;
always @(posedge clk) begin
		if (reset_col == 1)	temp <= 3'b000;
		else if (add_col == 1) temp <= temp+1;
			else temp<=temp;
		end	
always @(temp) begin
		col <= temp;
	end


endmodule
